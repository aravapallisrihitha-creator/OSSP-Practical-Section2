#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig)
{
      if(sig == SIGTERM)
           printf("\nSIGTERM recived!\n");
}

int main()
{
     signal(SIGTERM, handler);

     printf("Process ID: %d\n", getpid());
     printf("Waiting for SIGTERM...\n");

    while(1)
    {
     sleep(2);
    }

    return 0;

}
