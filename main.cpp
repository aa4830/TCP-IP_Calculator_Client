#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#include "Ui.h"
#include "Window.h"

#pragma comment(lib, "ws2_32")
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

using namespace std;


int SDL_main(int argc, char* argv[])
{
    UI MyUI;
    Window MyWindow;
    SDL_Event MyEvent;

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
        SDL_PollEvent(&MyEvent);
        MyUI.HandleEvent(MyEvent);
        switch (MyEvent.type)
        {
        case SDL_KEYDOWN:
            switch (MyEvent.key.keysym.sym)
            {
            }
        }
        MyWindow.Render(); // Surface 만들기
        MyUI.Render(MyWindow.GetSurface()); //Surface에 버튼 그리기
        MyWindow.Update(); // Surface에 그린 내용 반영하기.
    }

    SDL_Quit();

    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}