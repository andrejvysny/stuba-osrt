#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>


struct config {
    int socket_descriptor;
    struct sockaddr* sockaddr_p;
};



struct config create(){


    struct config conf;

    conf.socket_descriptor = 1;

    return conf;
}

typedef struct {
    int num;
    void *nums;
    int size;
} Mystruct;

Mystruct *mystruct(int num, int size)
{
    Mystruct *p = malloc(sizeof(MyStruct));

    return p;
}

struct a {
    int i;
};

struct a f(struct a x)
{
    struct a r = x;
    return r;
}



int sock(int port){

    // vytvorenie socketu
    int sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1)
    {
        printf("cannot create socket!\n");
        exit(0);
    }

    // nastavenie socketu
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    if (bind(sock_desc, (struct sockaddr*)&server, sizeof(server)) != 0)
    {
        printf("cannot bind socket!\n");
        close(sock_desc);
        exit(0);
    }

    return sock_desc;

}

struct sockaddr* conn_sock(int socket_desc){

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(7777);

    return connect()
}


int main(){

    int desc = sock(12344);




    char c = '\n';
    char *p_buf;



    return 0;
}




