#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <WinSock2.h>
#include <stdio.h>
#include "Text.h"
#include <string>

#pragma comment(lib, "ws2_32")
using namespace std;

class Socket
{
public:

    Socket()
    {
        WSAData wsaData;
        SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        WSAStartup(MAKEWORD(2, 2), &wsaData);
        sockaddr_in ServerSocketAddress;
        memset(&ServerSocketAddress, 0, sizeof(ServerSocketAddress));
        ServerSocketAddress.sin_family = AF_INET;
        ServerSocketAddress.sin_addr.s_addr = inet_addr("192.168.3.164");
        ServerSocketAddress.sin_port = htons(10880);
        connect(ServerSocket, (SOCKADDR*)&ServerSocketAddress, sizeof(ServerSocketAddress));


        while (1)
        {
            char SendBuffer[1024] = { 0, };
            string Result = MyText.CurrentText;
            strcpy(SendBuffer, Result.c_str());
            send(ServerSocket, SendBuffer, sizeof(SendBuffer), 0);

            char RecvBuffer[1024] = { 0, };
            int RecvByte = recv(ServerSocket, RecvBuffer, sizeof(RecvBuffer), 0);
            std::cout << RecvBuffer << std::endl;
        }

        closesocket(ServerSocket);
        WSACleanup();
    }
    ~Socket()
    {

    }
    void Send()
    {
        if (ServerSocket )
        {
            char SendBuffer[1024] = { 0, };
            string Result = MyText.CurrentText;
            strcpy(SendBuffer, Result.c_str());
            send(ServerSocket, SendBuffer, sizeof(SendBuffer), 0);
        }
    }
};