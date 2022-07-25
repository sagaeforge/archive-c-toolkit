#include <iostream>
#include <WinSock2.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#define BUF_SIZE    100
#define NAME_SIZE   20

using namespace std;

char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];

int main(int argc, char **argv) {
    WSADATA wsdata;
	int iRes = ::WSAStartup( MAKEWORD( 0x02, 0x02 ), &wsdata );
	if ( ERROR_SUCCESS != iRes )
		return -1;

	// 소켓 만들기
	SOCKET hSocket;
	hSocket = ::socket( PF_INET, SOCK_STREAM, 0 );
	if ( INVALID_SOCKET == hSocket )
		return -1;

	// 서버에 연결
	SOCKADDR_IN servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
	servAddr.sin_port = htons( 5000 );
	iRes = ::connect( hSocket, (LPSOCKADDR)&servAddr, sizeof( servAddr ) );

    char *buf = "sibal ";
    ::send( hSocket, buf, sizeof( buf ), 0 );

	::closesocket( hSocket );

	WSACleanup();
}
