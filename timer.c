/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarmOn = 0;
int alarmNum = 0;

time_t start, stop;

void alarmHandler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(5);
  alarmOn = 1;
  alarmNum++;
}

void sigintHandler(int signum)
{ //signal handler
  int totalTime;
  stop = time(NULL);
  totalTime = stop - start;

  printf("Number of alarms: %d in seconds: %d\n", alarmNum, totalTime);
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