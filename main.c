#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){

  srand(time(NULL));
  int f, f2, status;

  //fork 1st child process
  f = fork();

  //parent process running
  if (f){
    printf("This is the parent process. pid: %d\n", getpid());

    //fork 2nd child process
    f2 = fork();

    //2nd child process running
    if (f2 == 0){
      printf("Child 2 process pid: %d\n", getpid()); //print out pid
      int sleep_time = rand()%9+2; //random sleep time
      sleep(sleep_time);
      printf("Child 2 finished process.\n");
      return sleep_time; //returns sleep time as status
    }

    //wait for any child to finish
    int pid = wait(&status);

    //gets the pid and status from the first child to finish
    printf("pid of child: %d\tsleep time: %d\n", pid, WEXITSTATUS(status));
    printf("Parent finished processes.\n");
  }

  //1st child process running
  else{
    printf("Child 1 process pid: %d\n", getpid()); //print out pid
    int sleep_time = rand()%9+2; //random sleep time
    sleep(sleep_time);
    printf("Child 1 finished process.\n");
    return sleep_time; //returns sleep time as status
  }

  return 0;
}
