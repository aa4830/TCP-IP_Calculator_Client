#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include "process.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
using namespace std;

#pragma pack(push, 1) // ����ü�� ������� 1����Ʈ ���� ���ĵǵ��� ����
struct Data
{
    char Message;
};
#pragma pack(pop) // ���� �޸� ���� ������ ����. �ڷ� ����ϴ� ����ü���� ���ľȵǰ� �ϱ�.

Data PlayerData;

void RecvThread(void* Arg)
{
    Data RecvPacket;
    SOCKET ServerSocket = *(SOCKET*)(Arg);
    while (true)
    {
        int RecvByte = recv(ServerSocket, (char*)&RecvPacket, sizeof(RecvPacket), 0);
        if (RecvByte <= 0)
        {
            closesocket(ServerSocket);
            WSACleanup();
            _endthread();
            return;
        }
        else
        {
            PlayerData.Message =RecvPacket.Message;
            cout << PlayerData.Message << endl;
        }
    }
}

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
    _beginthread(RecvThread, 0, (void*)&ServerSocket);

    char Message;

    while (true)
    {
        Data SendPacket;
        cin >> Message;
        SendPacket.Message = Message;
        send(ServerSocket, (char*)&SendPacket, sizeof(SendPacket), 0);
    }

    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}