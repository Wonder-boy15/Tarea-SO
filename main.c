#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {

    pid_t pid;
    pid = fork();

        if (pid < 0) {

            fprintf(stderr, "Error al ejecutar fork()\n");
            return 1;
        }
        else if (pid == 0) {

            for (int i = 10000; i >= 1; i--){
                printf ("[HIJO] %d\n", i);
            }
        }
        else {
            for (int i = 1; i <= 10000; i++) {
            printf("[PADRE] %d\n", i);
            }
        }

        wait (NULL);

    return 0;

}