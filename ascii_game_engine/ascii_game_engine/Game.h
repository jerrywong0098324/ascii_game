// This is where the gameplay will occur

class Game
{
public:
	Game();
	~Game();

	static Game* GetInstance()
	{
		if (!instance)
			instance = new Game;
		return instance;
	};

	void Init();
	void Render();
	void Update();
	void Shutdown();

private:
	static Game *instance;
};