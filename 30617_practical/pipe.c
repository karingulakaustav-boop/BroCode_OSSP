#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main() {
    int pid;
    int fd[2];
    char msg[] = "hello child";
    char buffer[20];
    if(pipe(fd)==-1){
    perror("fail to create a pipe\n");
    exit(0);
}
if(pipe(fd2) == -1) {
   perror("fail to create pipe 2\n");
   exit(0);
}
    pid = fork();

    if(pid<0) {
       printf("failure in process creation\n");
       exit(0);
    }
    else if(pid == 0) {
       printf("i am in childprocess\n");
       close(fd[1]);
       read(fd[0], buffer, strlen(msg));
       printf("message from parent: %s", buffer);
       close(fd1[0]);
       close(2[1]);
    }
    else{
       printf("i am in parent process\n");
       close(fd[0]);
       write(fd[1], msg, strlen(msg));
       close(fd[1]);
}
}
