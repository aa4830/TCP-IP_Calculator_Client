#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <WinSock2.h>
#include <iostream>
#include "Text.h"
#include "Window.h"
#include <string>

#pragma comment(lib, "ws2_32")
using namespace std;

extern Window MyWindow;
extern Text MyText;

class Socket
{
public:
    SOCKET ServerSocket;
    Socket()
    {
        WSAData wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);
        ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        sockaddr_in ServerSocketAddress;
        memset(&ServerSocketAddress, 0, sizeof(ServerSocketAddress));
        ServerSocketAddress.sin_family = AF_INET;
        ServerSocketAddress.sin_addr.s_addr = inet_addr("192.168.0.108");
        ServerSocketAddress.sin_port = htons(10880);
        if (connect(ServerSocket, (SOCKADDR*)&ServerSocketAddress, sizeof(ServerSocketAddress)) == SOCKET_ERROR)
        {
            std::cout << WSAGetLastError() << std::endl;
            closesocket(ServerSocket);
            WSACleanup();
        }
    }

    void Recv()
    {
        char RecvBuffer[1024] = { 0, };
        int RecvByte = recv(ServerSocket, RecvBuffer, sizeof(RecvBuffer), 0);
        if (RecvByte > 0)
        {
            if (MyText.ResultTextSurface != nullptr)
            {
                SDL_Surface* ScreenSurface = MyWindow.GetSurface();
                SDL_FillRect(ScreenSurface, &MyText.ResultTextPosition, SDL_MapRGB(ScreenSurface->format, 240, 240, 240));
                SDL_FreeSurface(MyText.ResultTextSurface);
                MyText.ResultTextSurface = nullptr;
            }
            MyText.CurrentText.clear();
            MyText.CurrentText.assign(RecvBuffer);
            MyText.ResultTextSurface = TTF_RenderText_Solid(MyText.Font, MyText.CurrentText.c_str(), MyText.ResultTextColor);
            SDL_BlitSurface(MyText.ResultTextSurface, nullptr, MyWindow.GetSurface(), &MyText.ResultTextPosition);
        }
    }

    void CloseSocket()
    {
        closesocket(ServerSocket);
        WSACleanup();
    }

    void Send()
    {
                char SendBuffer[1024] = { 0, };
                string Result = MyText.CurrentText;
                strcpy(SendBuffer, Result.c_str());
                int result = (send(ServerSocket, SendBuffer, sizeof(SendBuffer), 0));
                if (result == SOCKET_ERROR)
                {
                    int errorCode = WSAGetLastError();
                    cout << errorCode << endl;
                }
                Recv();
    }
};