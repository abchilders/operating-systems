#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>


int main()
{
        int mypid, ReturnFromFork, ReturnFromFork2;

        mypid = getpid();

        ReturnFromFork = fork();
        
        if(ReturnFromFork < 0)
        {
                printf("An Error occured with fork (%d)\n", errno);
        }
        if(ReturnFromFork == 0)
        {
                execlp("./child_fork_thing", "child_fork_thing", NULL, NULL);
        }
        else
        {
                printf("I am the Parent. My child is %d\n",  ReturnFromFork);
                ReturnFromFork2 = fork();
                if(ReturnFromFork2 < 0)
                {
                        printf("An error occured woth fork (%d)\n", errno);
                }
                if(ReturnFromFork2 == 0)
                {
                        execlp("./child_fork_thing", "child_fork_thing",NULL, NULL);
                }
                else
                {
                        printf("I am the parent. My child is %d\n", ReturnFromFork2);
                }
                printf("I AM THE PARENT!!!! My pid is %d, my ppid is %d, the userid is %d\n", getpid(), getppid(), getuid());
                sleep(10);
        }
        return 0;
}

