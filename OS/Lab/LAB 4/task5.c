#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	int n,i=0;
	printf("Enter number of processes you want to create:");
	scanf("%d",&n);
	pid_t pid;
	while(i<n){
		pid=fork();
		if(pid == 0){
			printf("Inside Child process %d with PID:%d\n",i+1,getpid());
			exit(0);
		}
		else if(pid < 0){
			printf("Child creation failed");
			exit(1);
		}
		i++;
	}
	for (int i = 0; i < n; i++) {
        	wait(NULL);
    	}
	printf("Parent process with id:%d created %d child processes\n",getpid(),n);
	return 0;
}

