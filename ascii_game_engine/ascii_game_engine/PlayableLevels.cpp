#include "PlayableLevels.h"
#include "Console.h"

PlayableLevels::PlayableLevels()
{
	pos = &player.GetRefPosition();	
}

PlayableLevels::~PlayableLevels()
{

}

// Init the level
void PlayableLevels::Init()
{
	InitBuffer();
	
	const char* pauseMap = "../Game/Map/Default Maps/pause.txt";
	pause.Init(pauseMap);

	print = RendererManager::GetInstance()->GetPrint();
	Renderer::GetInstance()->SetLevel(this);
}

// Update the level
void PlayableLevels::Update()
{
	// if pause, don't update
	if (pause.Update())
		return;

	player.Update();
	SideScroll();
	UpdateBlocks();
}

// print out the chars
void PlayableLevels::Render()
{
	// if paused, print option menu then return
	if (pause.GetIsPaused())
	{
		pause.Render();
		return;
	}

	PrintMap();
	RenderBlocks();
}

// When Exiting the level
void PlayableLevels::Exit()
{
	pause.ExitP();
	player.Exit();
	DeleteBlocks();
}

/*******************************************************************
						GETTERS AND SETTERS
*******************************************************************/
int PlayableLevels::GetXBuffer() const
{
	return x_buffer;
}

int PlayableLevels::GetYBuffer() const
{
	return y_buffer;
}

/*******************************************************************
						BLOCKS FEATURE
*******************************************************************/
// Add block into a vector
void PlayableLevels::AddBlock(Block* block)
{
	blocks.push_back(block);
}

// Delete the block using the id
void PlayableLevels::DeleteBlock(Block* block)
{
	int i = block->GetID();
	// deallocating memory of this block
	blocks[i]->Exit();
	delete blocks[i];
	blocks[i] = nullptr;

	// removing this block from the vector
	blocks.erase(blocks.begin() + i);
}

// Clear any remaining memory of blocks from the level
void PlayableLevels::DeleteBlocks()
{
	while (blocks.size() > 0)
	{
		blocks[0]->Exit();
		delete blocks[0];
		blocks[0] = nullptr;
		blocks.erase(blocks.begin());
	}
}

// Returns true if theres a block at this position that is not this variable 'c'
char PlayableLevels::GetNotThisBlock(const Vector2& pos, const char& c)
{
	char res = (char)0; // returning this to an if-else statement will result in a false result

	// Loop through to find if there's a block that is not 'c'
	for (int i = 0; i < blocks.size(); ++i)
	{
		Vector2 p = blocks[i]->GetPosition(); // Get the position of this block
		char cb = blocks[i]->GetBlockCharacter(); // Get the block character
		// Check if it's at this position and there's no other block on it
		if (p.x == pos.x && p.y == pos.y && cb != c)
		{
			res = cb; // there's a block that's not 'c'
			break;
		}
	}
	return res;
}

// Returns the id of the block
int PlayableLevels::GetBlockID(const Vector2& pos)
{
	for (int i = 0; i < blocks.size(); ++i)
	{
		Vector2 p = blocks[i]->GetPosition();
		if (p.x == pos.x && p.y == pos.y)
			return blocks[i]->GetID();
	}
}

// Returns a reference to the block based on the position (nullptr if nth)
Block* PlayableLevels::GetBlock(const Vector2& pos) const
{
	for (int i = 0; i < blocks.size(); ++i)
	{
		Vector2 p = blocks[i]->GetPosition();
		if (p.x == pos.x && p.y == pos.y)
			return blocks[i];
	}
	return nullptr; // no such block in such position
}

// Returns a reference to the block based on the block's ID (nullptr if nth)
Block* PlayableLevels::GetBlock(const int& id) const
{
	Block* res = nullptr;
	// id < size and id cannot be negative number
	if (blocks.size() > id && 0 <= id)
		res = blocks[id];
	return res;
}

Player& PlayableLevels::GetRefPlayer()
{
	return player;
}

// ******************************************************************

bool PlayableLevels::GetIsPaused() const
{
	return pause.GetIsPaused();
}

// For sidescrolling
void PlayableLevels::SideScroll()
{
	ScrollRight();
	ScrollLeft();
	ScrollUp();
	ScrollDown();
}

int PlayableLevels::ScrollRightLimit(int multiplier, int divider)
{
	return Console::NewSBSize.X - Console::NewSBSize.X * multiplier / divider + x_buffer;
}

int PlayableLevels::ScrollLeftLimit(int multiplier, int divider)
{
	return Console::NewSBSize.X * multiplier / divider + x_buffer;
}

int PlayableLevels::ScrollUpLimit(int multiplier, int divider)
{
	return Console::NewSBSize.Y * multiplier / divider + y_buffer;;
}

int PlayableLevels::ScrollDownLimit(int multiplier, int divider)
{
	return Console::NewSBSize.Y - Console::NewSBSize.Y * multiplier / divider + y_buffer;
}

void PlayableLevels::ScrollRight()
{
	// unable to scroll right further (end of the map)
	if (x_buffer + Console::NewSBSize.X >= map.GetSizeX())
		return;

	// Only can scroll right at 1/3 (right side) of the map
	if (pos->x >= ScrollRightLimit(1, 4))
	{
		++x_buffer; // scrolling right
		UpdateBlocksOnScreen();
	}
}

void PlayableLevels::ScrollLeft()
{
	// 0 is at the border of left side of map
	if (x_buffer <= 0)
		return;

	// Only can scroll right at 1/3 (left side) of the map
	if (pos->x <= ScrollLeftLimit(1, 4))
	{
		--x_buffer; // scrolling right
		UpdateBlocksOnScreen();
	}
}

void PlayableLevels::ScrollUp()
{
	// at the top
	if (y_buffer <= 0)
		return;

	// Only can scroll right at 1/3 way of top of the map
	if (pos->y <= ScrollUpLimit(1, 4))
	{
		--y_buffer; // scrolling right
		UpdateBlocksOnScreen();
	}
}

void PlayableLevels::ScrollDown()
{
	// unable to scroll down further
	if (y_buffer + Console::NewSBSize.Y >= map.GetSizeY())
		return;

	// Only can scroll right at 1/3 (right side) of the map
	if (pos->y >= ScrollDownLimit(1, 4))
	{
		++y_buffer; // scrolling right
		UpdateBlocksOnScreen();
	}
}

// init buffer based on player's pos, putting the playing in the middle of the screen
void PlayableLevels::InitBuffer()
{
	x_buffer = 0;
	y_buffer = 0;

	// TODO: rework formula for x and y buffer upon load
	InitXBuffer();
	InitYBuffer();
	UpdateBlocksOnScreen();
}

void PlayableLevels::InitXBuffer()
{
	// put the player in the middle of the screen
	if (pos->x > Console::NewSBSize.X * 0.5f)
		x_buffer = pos->x - Console::NewSBSize.X * 0.5f;

	int x_buffer_limit = map.GetSizeX() - Console::NewSBSize.X;
	// Limit the x_buffer as player's position is towards the edge of the game map
	if (x_buffer > x_buffer_limit)
	{
		int temp = x_buffer - x_buffer_limit;
		x_buffer -= temp;
	}
}

void PlayableLevels::InitYBuffer()
{
	// put the player in the middle of the screen
	if (pos->y > Console::NewSBSize.Y * 0.5f)
		y_buffer = pos->y - Console::NewSBSize.Y * 0.5f;

	int y_buffer_limit = map.GetSizeY() - Console::NewSBSize.Y;
	// Limit the x_buffer as player's position is towards the edge of the game map
	if (y_buffer > y_buffer_limit)
	{
		int temp = y_buffer - y_buffer_limit;
		y_buffer -= temp;
	}
}

void PlayableLevels::PrintMap()
{
	// Put the map into print's 2d dynamic array
	for (int i = y_buffer; i < YLimit(); ++i)
	{
		// printing the map one character at a time
		for (int j = x_buffer; j < XLimit(); ++j)
			Renderer::GetInstance()->Add(j - x_buffer, i - y_buffer, 1, Colours::TBC, map.GetCharacter(j, i));
	}
}

int PlayableLevels::XLimit()
{
	int limit = x_buffer + Console::NewSBSize.X;
	if (limit > map.GetSizeX()) // safe check
		limit = map.GetSizeX();
	return limit;
}

int PlayableLevels::YLimit()
{
	int limit = y_buffer + Console::NewSBSize.Y;
	if (limit > map.GetSizeY()) // safe check
		limit = map.GetSizeY();
	return limit;
}

// Update blocks
void PlayableLevels::UpdateBlocks()
{
	for (int i = 0; i < blocks_on_screen.size(); ++i)
		blocks_on_screen[i]->Update();
}

// Render blocks
void PlayableLevels::RenderBlocks()
{
	for (int i = 0; i < blocks_on_screen.size(); ++i)
		blocks_on_screen[i]->Render();
}

// Adding blocks into the update_blocks vector
void PlayableLevels::UpdateBlocksOnScreen()
{
	// clearing vector
	blocks_on_screen.clear();

	for (int i = 0; i < blocks.size(); ++i)
	{
		const int x = blocks[i]->GetPosition().x;
		const int y = blocks[i]->GetPosition().y;

		if (x >= x_buffer && x <= XLimit() && y >= y_buffer && y <= YLimit())
			blocks_on_screen.push_back(blocks[i]);
	}
}