#include <stdio.h>
#include <stdlib.h>

#include <winsock2.h>
#include <sys/types.h>

#include <Ws2tcpip.h>

int main(int argc, char* argv )
{
    char *address;
    address = argv[1];
    // Create socket
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define address
    struct sockaddr_in remote_address;
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(80);

    remote_address.sin_addr.s_addr = inet_addr(address);

    connect(client_socket, (struct sockaddr*)&remote_address, sizeof(remote_address));

    char request[] = "GET / HTTP/1.1 \r\n\r\n";
    char response[4096];

    send(client_socket, request,sizeof(request), 0);

    recv(client_socket, response, sizeof(response), 0);

    printf("response from server: %s\n", response);

    closesocket(client_socket);

    return 0;
}
