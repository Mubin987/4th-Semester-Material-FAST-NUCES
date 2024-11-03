//21K-4827
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/wait.h>

int main(){
pid_t pid;
pid=fork();
if(pid>0){
void* shm_mem;
int shm_id;
char buff[100];
shm_id=shmget((key_t)1122,1024,0777|IPC_CREAT);
printf("Target memory location %d\n",shm_id);
shm_mem=shmat(shm_id,NULL,0);
read(0,buff,100);
strcpy(shm_mem,buff);
printf("Data written in parent: %s\n",(char *)shm_mem);
}
if(pid==0){
wait(NULL);
void* shm_mem;
int shm_id1;
shm_id1=shmget((key_t)1122,1024,0777|IPC_CREAT);
printf("Target memory location %d\n",shm_id1);
shm_mem=shmat(shm_id1,NULL,0);
printf("Data read in child: %s\n",(char *)shm_mem);
//shmdt(shm_id1,NULL,0);
shmctl(shm_id1,IPC_RMID,0);
exit(0);
}
if(pid<0){
printf("Child craetion failed\n");
exit(1);
}
return 0;
}



