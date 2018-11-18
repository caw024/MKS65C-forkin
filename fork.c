#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

//I usedd GeeksforGeeks to better understand how fork and wait works.
//Also looked at simon's post on qaf to see how to do multiple forks at once.

int main(){
  int randfd;
  int arr[0];
  int stat;
  int l;
  int m;
  int i = 0;

 
  printf("beginning of parent\n");

  for  (i; i < 2; i++){
    //child process
    if (fork() == 0){
      randfd = open("/dev/random", O_RDONLY);
      l = read(randfd, arr, sizeof(int));
      m = close(randfd);
  
      l = (l % 15) + 5;
      sleep(l);
      printf("child finished sleeping\n");

      printf("The child slept for %d seconds\n", l);
      return 0;
    }

    //parent process
    else{
      printf("parent is waiting for child to finish:\n");
      waitpid(-1,&stat,0);
      if (WIFEXITED(stat)){
	printf("parent is done waiting\n");
      }
    }

  }

    
  
}


