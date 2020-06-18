#include "ControllerHandler.h"
#include "MemoryLeak.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (SetConsoleCtrlHandler(CtrlHandler, TRUE))
	{
		Application app;
		myApp = &app;
		app.Init();
		app.Run();
		app.Exit();
	}
}