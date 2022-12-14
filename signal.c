/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(5);
  alarmOn = 1;
  
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 1 second
  while(1){
    alarmOn = 0;
    alarm(5);
    
    while (!alarmOn);
    printf("Turing was right!\n")
  } 
  return 0; //never reached
}