
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <winsock.h>
#include <sys/types.h>

int main(void)
{
    // Open and Read HTML file
    FILE *html_data;
    if(!html_data == fopen("index.html","r"))
        printf("Error in opening file!\n");

    char response_data[1024];
    fgets(response_data, sizeof(response_data), html_data);

    // Response to the requseted page
    char http_header[2028] = "HTTP/1.1 200 OK\r\n\n";
    strcat(http_header, response_data); // Puts response_data in http_header

    // Create socket
    SOCKET server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define the address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8001);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int bind_status = bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr));
    if(bind_status < 0)
        printf("Error in binding!\n\n");

    listen(server_socket, 4);

    int client_socket;
    while(1)
    {
        client_socket = accept(server_socket, NULL, NULL );
        send(server_socket, http_header, sizeof(http_header), 0);
        closesocket(server_socket);
    }
    return 0;
}
