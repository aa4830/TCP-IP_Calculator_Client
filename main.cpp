#include _WINSOCK_DEPRECATED_NO_WARNINGS // ���Ϻ��� ���� include�ؾ���
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")

int main()
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	sockaddr_in ServerSocketAddress; // Server�ּ� ����ü ����
	memset(&ServerSocketAddress, 0, sizeof(ServerSocketAddress)); //����ü �ʱ�ȭ

	ServerSocketAddress.sin_family = AF_INET; //����ü ����1
	ServerSocketAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); //����ü ����2
	ServerSocketAddress.sin_port = htons(10880); //����ü ����3

	SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	connect(ServerSocket, (SOCKADDR*)&ServerSocketAddress, sizeof(ServerSocketAddress));

		char Buffer[1024] = { 0, };
	int SendLength = send(ServerSocket, Buffer, (int)strlen(Buffer), 0);

	char Message[1024] = { 0, };
	recv(ServerSocket, Message, sizeof(Message), 0);

	WSACleanup();

	return 0;
}