//21K-4827
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(){
FILE *fptr;
char buffer[100];
fptr= fopen("~/home/student/file.txt","r");
int fd=open("file.txt",O_RDONLY);
read(fd,buffer,100);
printf("From file: %s",buffer);

pid_t pid;
for(int i=0;i<2;i++){
pid=fork();
if(pid>0){

}
if(pid==0){
printf("Child process has id %d and parent id is %d\n",getpid(),getppid());
exit(0);
}
if(pid<0){
printf("Child creation failed\n");
exit(1);
}


}
wait(NULL);
wait(NULL);
printf("Parent process has id %d\n",getpid());
return 0;
}



