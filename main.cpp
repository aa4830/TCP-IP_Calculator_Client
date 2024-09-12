#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "SDL.h"
#include "Text.h"
#include <iostream>
#include "Ui.h"
#include "Socket.h"
#include "Window.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

using namespace std;

Window MyWindow;
Text MyText;

int SDL_main(int argc, char* argv[])
{
    UI MyUI;
    SDL_Event MyEvent;
    Socket MySocket;

    MyWindow.Render(); // Surface 만들기
    MyUI.Render(MyWindow.GetSurface()); //Surface에 버튼 그리기
    MyWindow.DrawResultBoard();
    MyWindow.Draw1TextOnButton();
    MyWindow.Draw2TextOnButton();
    MyWindow.Draw3TextOnButton();
    MyWindow.Draw4TextOnButton();
    MyWindow.Draw5TextOnButton();
    MyWindow.Draw6TextOnButton();
    MyWindow.Draw7TextOnButton();
    MyWindow.Draw8TextOnButton();
    MyWindow.Draw9TextOnButton();
    MyWindow.Draw0TextOnButton();
    MyWindow.DrawDivideOnButton();
    MyWindow.DrawMinusOnButton();
    MyWindow.DrawAddOnButton();
    MyWindow.DrawMultiplyOnButton();
    MyWindow.DrawResultButton();
    MyWindow.DrawLastTextDeleteButton();
    MyWindow.TextClearButton();

    bool bIsRunning = true;
    while (bIsRunning)
    {
        while (SDL_PollEvent(&MyEvent))
        {
            MyUI.HandleEvent(MyEvent);
            if (MyEvent.type == SDL_QUIT)
            {
                bIsRunning = false; 
            }
        }
        MyWindow.Update();
    }

    MySocket.CloseSocket();
    SDL_Quit();
    return 0;
}
