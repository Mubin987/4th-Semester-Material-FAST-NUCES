#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	int n=3;int temp=3;
	pid_t pid[n];
	for(int i=0;i<n;i++){
	temp--;
		pid[i]=fork();
		if(pid[i] == 0){
			printf("Inside Child process %d with PID:%d\n",i+1,getpid());
		if(temp==i){
			
			exit(0);
		}
		}
		else if(pid[i] < 0){
			printf("Child creation failed");
			exit(1);
		}
	}
	waitpid(pid[2], NULL, 0);
   	waitpid(pid[1], NULL, 0);
   	waitpid(pid[0], NULL, 0);
	printf("Parent process with id:%d created %d child processes\n",getpid(),n);
	return 0;
}

