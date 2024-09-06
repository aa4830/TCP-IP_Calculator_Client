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
        string Input;
        char SendBuffer[1024] = { 0, };

        cout << "계산할 값을 입력해주세요" << endl;
        cout << "Ex) 1+1" << endl;
        cin >> Input;

        strcpy(SendBuffer, Input.c_str());
        send(ServerSocket, SendBuffer, sizeof(SendBuffer), 0);

        char RecvBuffer[1024] = { 0, };
        int RecvByte = recv(ServerSocket, RecvBuffer, sizeof(RecvBuffer), 0);

        cout << "결과:" << RecvBuffer << endl;
    }

    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}