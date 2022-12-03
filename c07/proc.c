#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void sigusr1_kill();

void sigusr1_revenge();

int main() {
    pid_t pid1, pid2, pid3;

    /* get child process */

    if ((pid1 = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid1 > 0) {
        if ((pid2 = fork()) < 0) {
            perror("fork");
            exit(1);
        }
    }

    if (pid1 > 0 && pid2 > 0) {
        if ((pid3 = fork()) < 0) {
            perror("fork");
            exit(1);
        }
    }


    if (pid1 == 0) { /* child 1 */
        signal(SIGUSR1, sigusr1_kill); /* set function calls */
        for (;;)sleep(1); /* loop for ever */
    }

    if (pid2 == 0) { /* child 1 */
        signal(SIGUSR1, sigusr1_kill); /* set function calls */
        for (;;)sleep(1); /* loop for ever */
    }

    if (pid3 == 0) { /* child 1 */
        signal(SIGUSR1, sigusr1_revenge); /* set function calls */
        for (;;)sleep(1); /* loop for ever */
    }

    if (pid1 > 0 && pid2 > 0 && pid3 > 0) { // PARENT
        printf("PARENT: Sleeping\n");
        sleep(10);
        printf("\nPARENT: Killing pid1 %d \n\n", pid1);
        kill(pid1, SIGUSR1);
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: Killing pid2 %d \n\n", pid2);
        kill(pid2, SIGUSR1);
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: Killing pid3 %d \n\n", pid3);
        kill(pid3, SIGUSR1);
        sleep(3);
    }

    return 0;
}

void sigusr1_kill() {
    signal(SIGUSR1, sigusr1_kill); /* reset signal - signal sa znova namapuje na*/
    printf("Oh Daddy don't kill me! X_X\n");
    exit(0);
}

void sigusr1_revenge() {
    signal(SIGUSR1, sigusr1_kill); /* reset signal */
    printf("Oh Daddy don't kill me!\n Not so easy! Killing %d\n ", getppid());
    kill(getppid(), SIGKILL);

    printf("What have i done ?!\n");
    exit(0);
}