#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){
  int child1 = fork();
  // int child2 = fork();
  int fd;

  printf("pid: %d \n", getpid());

  if (child1 == 0){
    fd = open("/dev/random", O_RDONLY);
    printf("fd: %d\n", fd);

    sleep((fd % 15) + 5);
    close(fd);
    printf("child finished waiting\n");

  }
  else{
    printf("waiting for child to finish:\n");
    int * a = wait(2);
    printf("parent is done\n");
    
  }


}


