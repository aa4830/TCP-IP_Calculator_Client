#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "SDL.h"
#include "Text.h"
#include "ClientSocket.h"
#include <iostream>
#include "Ui.h"
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
    ClientSocket MyClientSocket;

    MyWindow.Render(); // Surface �����
    MyUI.Render(MyWindow.GetSurface()); //Surface�� ��ư �׸���

    MyWindow.DrawResultBoard();
    MyWindow.Draw1TextOnButton();
    MyClientSocket.CreateSocket();


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
            else if (MyEvent.type == SDL_KEYDOWN)
            {
                    cout << "KeyDown" << endl;
            }
        }
        MyWindow.Update(); // Surface�� �׸� ���� �ݿ��ϱ�.
    }

    SDL_Quit();
    MyClientSocket.CloseSocket();
    return 0;
}