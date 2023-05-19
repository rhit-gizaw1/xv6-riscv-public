#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// Process with a very low priority -> leading to less tickets. Has a long process so ticket val should be 10 most of the time
// Process with very high priority -> huge amount of tickets -> does not have muhc logic
int main(int argc, char *argv[])
{
    int pid;
    int count = 0;

    pid = fork();
    if (pid == 0)
    {
        // Child Process
        setPriority(1);
        for (int x = 0; x < 2000000; x++)
        {
            count++;
        }
    }
    else
    {
        setPriority(1000);
        for (int x = 0; x < 20; x++)
        {
            count++;
        }
    }

    return 0;
}
