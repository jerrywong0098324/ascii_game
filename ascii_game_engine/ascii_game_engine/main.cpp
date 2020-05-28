#include "Application.h"

// used for debugging (checking for memory leaks)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

int main()
{
	Application app;
	app.Init();
	app.Run();
	app.Exit();

	_CrtDumpMemoryLeaks();
}