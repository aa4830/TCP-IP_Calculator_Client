#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include "process.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
using namespace std;

#pragma pack(push, 1)
struct Data
{
    short Number1;
    char Operator;
    short Number2;
};
#pragma pack(pop) 

Data PlayerData;

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

    char Message;

    while (true)
    {
        Data SendPacket;

        short Number1;
        char Operator;
        short Number2;
        cout << "숫자1을 입력해주세요" << endl;
        cin >> Number1;
        cout << "연산자를 입력해주세요" << endl;
        cin >> Operator;
        cout << "숫자2을 입력해주세요" << endl;
        cin >> Number2;

        SendPacket.Number1 = Number1;
        SendPacket.Operator = Operator;
        SendPacket.Number2 = Number2;
        send(ServerSocket, (char*)&SendPacket, sizeof(SendPacket), 0);
        char Buffer[1024];
        int RecvByte = recv(ServerSocket, Buffer, (int)sizeof(Buffer), 0);

        cout << "결과:" << Buffer << endl;
    }

    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}