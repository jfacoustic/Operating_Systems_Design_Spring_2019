#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("hello, world (pid: %d)\n", (int) getpid());
  for(int i = 0; i < 1000; i++) {
  int rc = fork();
  //printf("rc = fork() = %d \n", rc);
  if (rc < 0) {
    //fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0) {
    //printf("hello, I am a child (pid: %d)\n", (int) getpid());
  }
  else {
    //printf("hello, I am the parent of %d (pid:%d)\n", rc, (int) getpid());
  }
  printf("%d", (int) getpid());
  }
  return 0;
  
}
