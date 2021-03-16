
#include "Network/__USER__NETWORK__.h"

int main()
{
    int client_socket;
    SocketAddr_in server_Addr;
    char message[1024] = { 0x00, };

    client_socket = socket(PF_INET, SOCK_STREAM, 0);
    if(client_socket == -1)
    {
        printf("ERR> Socket ERROR\n");
        exit(1);
    }

    memset(&server_Addr, 0, sizeof(server_Addr));
    server_Addr.sin_family=AF_INET;
    server_Addr.sin_addr.s_addr=inet_addr(__SERVER_IP__);
    server_Addr.sin_port=htons(__SERVER_PORT__);

    if(connect(client_socket, (SocketAddr*) &server_Addr, sizeof(server_Addr)) == -1)
    {
        printf("ERR> Connect ERROR\n");
        exit(1);
    }

    if(read(client_socket, message, sizeof(message)-1) == -1)
    {
        printf("ERR> Read ERROR\n");
        exit(1);
    }
    printf("Message From Server : %s\n", message);

    close(client_socket);
    return 0;
}