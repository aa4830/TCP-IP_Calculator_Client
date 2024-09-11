#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "SDL.h"
#include <SDL_ttf.h>
#include <stdio.h>
#include "Text.h"
#include <iostream>
#include <WinSock2.h>
#include "Ui.h"
#include "Window.h"

#pragma comment(lib, "ws2_32")
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

Window MyWindow;
Text MyText;

using namespace std;

int SDL_main(int argc, char* argv[])
{
    UI MyUI;
    SDL_Event MyEvent;

    MyWindow.Render(); // Surface 만들기
    MyUI.Render(MyWindow.GetSurface()); //Surface에 버튼 그리기

    WSAData wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    sockaddr_in ServerSocketAddress;
    memset(&ServerSocketAddress, 0, sizeof(ServerSocketAddress));
    ServerSocketAddress.sin_family = AF_INET;
    ServerSocketAddress.sin_addr.s_addr = inet_addr("192.168.3.164");
    ServerSocketAddress.sin_port = htons(10880);

    SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    connect(ServerSocket, (SOCKADDR*)&ServerSocketAddress, sizeof(ServerSocketAddress));

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
                    cout << "X" << endl;
                    if (MyText.TextSurface != nullptr)
                    {
                        SDL_FreeSurface(MyText.TextSurface);
                    }
                    MyText.TextSurface = TTF_RenderText_Solid(MyText.Font, "X", MyText.TextColor);
                    if (MyText.TextSurface == nullptr)
                    {
                        printf("Failed to render text: %s\n", TTF_GetError());
                    }
                    else
                    {
                        SDL_BlitSurface(MyText.TextSurface, nullptr, MyWindow.GetSurface(), &MyText.TextPosition);
                    }
            }
        }
        MyWindow.Update(); // Surface에 그린 내용 반영하기.
    }

    SDL_Quit();

    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}