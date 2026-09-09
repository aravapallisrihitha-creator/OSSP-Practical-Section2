#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void child_handler(int sig)
{
     printf("SIGCHLD recived: Child has terminated\n");
     wait(NULL);
}

int main()
{
    signal(SIGCHLD, child_handler);

   pid_t pid = fork();

   if(pid == 0)
   {
      printf("Child is running..\n");
      sleep(2);
      printf("Child is existing...\n");
   }

   return 0;

}
