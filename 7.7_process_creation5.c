#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid;

    for(int i = 0; i < 4; i++)
        pid = fork();
    printf("Hello, fork() %d!\n", pid);

    return 0;
}