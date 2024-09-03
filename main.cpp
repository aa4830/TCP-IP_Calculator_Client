#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include "process.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
using namespace std;

#pragma pack(push, 1) // 구조체의 멤버들이 1바이트 경계로 정렬되도록 설정
struct Data
{
    string Message;
    string Name;
};
#pragma pack(pop) // 이전 메모리 정렬 설정을 복원. 뒤로 사용하는 구조체들은 정렬안되게 하기.

int main() {
    WSAData wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    sockaddr_in ServerSocketAddress;
    memset(&ServerSocketAddress, 0, sizeof(ServerSocketAddress));
    ServerSocketAddress.sin_family = AF_INET;
    ServerSocketAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    ServerSocketAddress.sin_port = htons(10880);

    SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    connect(ServerSocket, (SOCKADDR*)&ServerSocketAddress, sizeof(ServerSocketAddress));
    _beginthread(RecvThread, 0, (void*)&ServerSocket);
    char buffer[1024] = { 0, };
    int recvBytes = recv(ServerSocket, buffer, sizeof(buffer) - 1, 0); 


    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}
void RecvThread(void* Arg)
{
    Data Packet;
    char Buffer[1024] = { 0, };
    SOCKET ServerSocket = *(SOCKET*)(Arg);
    while (true)
    {
        int RecvByte = recv(ServerSocket, (char*)&Packet, sizeof(Packet), 0);
        if (RecvByte <= 0)
        {
            break;
        }
        else
        {
            Buffer[RecvByte] = '\0'; // 문자열의 끝을 나타내기 위해 널 종료를 추가
            cout << Buffer << endl;
        }
    }
}