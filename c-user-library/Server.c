
#include "Network/__USER__NETWORK__.h"

int main(int argc, char *argv[])
{
    int server_sorcket;
    int client_sorcket;

    SocketAddr_in server_addrs;
    SocketAddr_in client_addrs;
    socklen_t client_addrs_size;

    server_sorcket = socket(PF_INET, SOCK_STREAM, 0);
    if(server_sorcket == -1)
    {
        printf("ERR> Socket ERROR\n");
        exit(1);
    }

    memset(&server_addrs, 0, sizeof(server_addrs));
    server_addrs.sin_family=AF_INET;
    server_addrs.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addrs.sin_port=htons(__SERVER_PORT__);

    if(bind(server_sorcket, (struct sockaddr *)&server_addrs, sizeof(server_addrs)) == -1)
    {
        printf("ERR> Bind ERROR\n");
        exit(1);
    }

    if(listen(server_sorcket, 10) == -1)
    {
        printf("ERR> Listen ERROR\n");
        exit(1);
    }

    client_addrs_size = sizeof(client_addrs);
    client_sorcket=accept(server_sorcket, (struct sockaddr*)&client_addrs, &client_addrs_size);
    if(client_sorcket==-1)
    {
        printf("ERR> Accept ERROR\n");
        exit(1);
    }

    char message[] = "Hello NetWork Programming World!!\n";
    write(client_sorcket, message, sizeof(message));

    close(client_sorcket);
    close(server_sorcket);


    return 0;
}
