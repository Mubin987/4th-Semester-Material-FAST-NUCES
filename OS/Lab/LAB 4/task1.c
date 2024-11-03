#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int parent=getpid();
    pid_t pid = fork();
    if (pid > 0)  {
    	
    	wait(NULL);
    	sleep(5);
    	printf("\nI am the parent process with PID:%d and my child PID is:%d \n",getpid(),pid);
    }
    else if (pid == 0) {
        printf("\nI'm the child process! My PID is %d My parent's PID is: %d", getpid(),parent);
        int i=0;
        while(i<10){
        	if(i%2==1)
        		printf(" %d ",i);
        	i++;
        }
        printf("\nChild Ends\n");
    }
    if (pid < 0) {
        printf("\nUnsuccessful child process creation\n");
        exit(1);
    }
}

