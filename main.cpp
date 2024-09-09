#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "process.h"
#include <WinSock2.h>

#pragma comment(lib, "ws2_32")

using namespace std;

int SDL_main(int argc, char* argv[])
{
    WSAData wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    sockaddr_in ServerSocketAddress;
    memset(&ServerSocketAddress, 0, sizeof(ServerSocketAddress));
    ServerSocketAddress.sin_family = AF_INET;
    ServerSocketAddress.sin_addr.s_addr = inet_addr("192.168.3.164");
    ServerSocketAddress.sin_port = htons(10880);

    SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    connect(ServerSocket, (SOCKADDR*)&ServerSocketAddress, sizeof(ServerSocketAddress));

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* MyWindow = SDL_CreateWindow("Client", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
    SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        | SDL_RENDERER_TARGETTEXTURE);
    SDL_Event MyEvent;

    bool bIsRunning = true;

    while (bIsRunning)
    {
        SDL_PollEvent(&MyEvent);
        switch (MyEvent.type)
        {
        case SDL_QUIT:
            bIsRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (MyEvent.key.keysym.sym)
            {
            case SDLK_q:

            }
        }
    }
    SDL_DestroyRenderer(MyRenderer);
    SDL_DestroyWindow(MyWindow);
    SDL_Quit();


    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}