#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	int n=2;
	pid_t pid,pid1;
	for(int i=0;i<n;i++){
		pid=fork();
		if(pid == 0){
			printf("Inside Child process %d with PID:%d\n",i+1,getpid());
			for(int j=0;j<n;j++){
		pid1=fork();
		if(pid1 == 0){
			printf("Inside GrandChild process %d with PID:%d\n",i+1,getpid());
			exit(0);
		}
		else if(pid1 < 0){
			printf("GrandChild creation failed");
			exit(1);
		}
	}
			exit(0);
		}
		else if(pid < 0){
			printf("Child creation failed");
			exit(1);
		}
	}
	for (int i = 0; i < n; i++) {
        	wait(NULL);
    	}
	printf("Parent process with id:%d created 6 child processes\n",getpid());
	return 0;
}

