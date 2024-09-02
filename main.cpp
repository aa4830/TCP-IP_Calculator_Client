#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
using namespace std;

int main() {
    WSAData wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup failed with error: " << WSAGetLastError() << endl;
        return 1;
    }

    sockaddr_in ServerSocketAddress;
    memset(&ServerSocketAddress, 0, sizeof(ServerSocketAddress));
    ServerSocketAddress.sin_family = AF_INET;
    ServerSocketAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    ServerSocketAddress.sin_port = htons(10880);

    SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ServerSocket == INVALID_SOCKET) {
        cout << "Socket creation failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    if (connect(ServerSocket, (SOCKADDR*)&ServerSocketAddress, sizeof(ServerSocketAddress)) == SOCKET_ERROR) {
        cout << "Connection failed with error: " << WSAGetLastError() << endl;
        closesocket(ServerSocket);
        WSACleanup();
        return 1;
    }

    // 서버로부터 "10 + 20" 문자열 수신
    char buffer[1024] = { 0, };
    int recvBytes = recv(ServerSocket, buffer, sizeof(buffer) - 1, 0); // -1 for null terminator
    if (recvBytes > 0) {
        buffer[recvBytes] = '\0'; // Null-terminate the received data
        printf("Client received: %s\n", buffer);

        // 사용자로부터 결과 입력 받기
        int result;
        cout << "Enter the result for the expression: ";
        cin >> result;

        // 결과를 서버에 전송
        string resultStr = to_string(result);
        send(ServerSocket, resultStr.c_str(), (int)resultStr.length(), 0);

        // 서버로부터 메시지 수신
        char response[1024] = { 0 };
        recvBytes = recv(ServerSocket, response, sizeof(response) - 1, 0); // -1 for null terminator
        if (recvBytes > 0) {
            response[recvBytes] = '\0'; // Null-terminate the received data
            printf("Client received message from server: %s\n", response);
        }
        else if (recvBytes == 0) {
            cout << "Connection closed by server." << endl;
        }
        else {
            cout << "recv failed with error: " << WSAGetLastError() << endl;
        }
    }
    else if (recvBytes == 0) {
        cout << "Connection closed by server." << endl;
    }
    else {
        cout << "recv failed with error: " << WSAGetLastError() << endl;
    }

    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}