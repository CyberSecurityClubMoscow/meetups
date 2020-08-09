#include <unistd.h>
#include <stdio.h>

int main()
{
  int pid;
  int count = 100;
  short int isChild = 0;

  for(int i = 0; i < count;i++){  

    pid = fork();

    if ( pid != 0 ){
      printf("My new child: %d\n",pid);
    } else {
      isChild = 1;
      sleep(60);
      return(0);
    }

  }
  return(0);
}
