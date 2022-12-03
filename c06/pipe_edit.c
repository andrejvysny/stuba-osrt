#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {

    int fd[2], nbytes;
    pid_t childpid;
    int buf;

    pipe(fd);

    if ((childpid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if (childpid == 0) {

        int number = 0;
        printf("Zadajte cislo: ");
        scanf("%d", &number);

        /* Read in a string from the pipe */
        write(fd[1], &number, sizeof(number));

        sleep(2);
        nbytes = (int) read(fd[0],&buf,sizeof (buf));

        printf("SENDER RECIVIED: %d ... %d",buf, nbytes);

        exit(0);

    } else {

        /* Child process closes up input side of pipe */

        /* Send "string" through the output side of pipe */
        nbytes = (int) read(fd[0], &buf, sizeof(buf));

        if(nbytes)
            write(fd[1],&buf,sizeof(buf));
            sleep(2);

        exit(0);

    }

    exit(0);
}
