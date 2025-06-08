#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
        sleep(10);
        printf("I am the child. My pid is %d. My ppid is %d. My uid is %d.\n", getpid(), getppid(), getuid());
        return 0;
}
