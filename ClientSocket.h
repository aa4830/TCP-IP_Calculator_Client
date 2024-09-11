#pragma once
#include <WinSock2.h>
#include <stdio.h>


#pragma comment(lib, "ws2_32")

class ClientSocket
{
public:

	WSAData wsaData;
	SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	ClientSocket()
	{

	}
	~ClientSocket()
	{

	}

	void CreateSocket()
	{
		WSAStartup(MAKEWORD(2, 2), &wsaData);

		sockaddr_in ServerSocketAddress;
		memset(&ServerSocketAddress, 0, sizeof(ServerSocketAddress));
		ServerSocketAddress.sin_family = AF_INET;
		ServerSocketAddress.sin_addr.s_addr = inet_addr("192.168.3.164");
		ServerSocketAddress.sin_port = htons(10880);
		connect(ServerSocket, (SOCKADDR*)&ServerSocketAddress, sizeof(ServerSocketAddress));

	}
	void CloseSocket()
	{
		closesocket(ServerSocket);
		WSACleanup();
	}
};