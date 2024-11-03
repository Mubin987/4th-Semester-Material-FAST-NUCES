#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int p = 4;
    
    for (int i = 0; i < p; i++) {
        pid_t pid = fork();
        
        if (pid == 0) {
            printf("Parent process %d with PID %d created by grandparent process with PID %d\n",p, getpid(), getppid());
            
            pid_t cpid = fork();
        
        if (cpid == 0) {
            printf("child process 1 with PID %d created by parent process with PID %d\n\n",getpid(), getppid());
            exit(0);
        }
        
        else if (cpid > 0) {
            printf("Parent process with PID %d created child process with PID %d\n", getpid(), cpid);
            wait(NULL);
        } else {
            printf("Fork failed\n");
            exit(1);
        }
        exit(0);
        }
        
        else if (pid > 0) {
            printf("GrandParent process with PID %d created parent process with PID %d\n", getpid(), pid);
            wait(NULL);
        } else {
            printf("Fork failed\n");
            exit(1);
        }
    }
    
    printf("GrandParent process with PID %d has finished creating 4 child processes\n", getpid());
    
    return 0;
}

