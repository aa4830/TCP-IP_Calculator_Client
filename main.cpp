#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include "process.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
using namespace std;

int main() 
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


    while (1)
    {
        char Number;
        char Buffer[1024] = { 0, };

        cout << "계산할 값을 입력해주세요" << endl;
        cout << "Ex) 1+1" << endl;
        cin >> Number;

        sprintf(Buffer, "%d", Number);

        send(ServerSocket, Buffer, (int)sizeof(Buffer), 0);

        char buffer[1024];
        int RecvByte = recv(ServerSocket, buffer, (int)sizeof(buffer), 0);

        cout << "결과:" << buffer << endl;
    }

    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}