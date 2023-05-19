#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


//Process with a lot of forks 
int main(int argc, char *argv[])
{
    int pid;
    int count = 0;
    // printf("Parent process with PID = %d\n", getpid());
    for (int i = 0; i < 50; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            // Child Process
            setPriority(i);
            // printf("Child process %d with PID = %d\n", i + 1, getpid());
            for (int x = 1; x <= (i + 1); x++)
            {
                count++;
                // printf("Child process %d with PID = %d\n", i + 1, getpid());
            }
        }
        wait(0);
    }
    // printf("Count is %d\n", count);

    return 0;
}
