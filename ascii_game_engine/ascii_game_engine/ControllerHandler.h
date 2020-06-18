#include "Application.h"
#include <stdio.h> 
#include <Windows.h>

Application* myApp;

// Prevent any memory leak when program is close
void Terminate()
{
    myApp->Terminate();
}

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
    switch (fdwCtrlType)
    {
        // When window console x button is pressed
    case CTRL_CLOSE_EVENT:
        Terminate();
        printf("Ctrl-Close event\n\n");
        return TRUE;

    default:
        return FALSE;
    }
}