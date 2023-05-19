#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

//Normal test case 
int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        int childFork = fork();
        if (!childFork)
        {
            setPriority(2);
            int count = 0;
            for (int i = 0; i < 20000000; i++)
            {
                count++;
            }
            exit(0);
        }
        else
        {
            setPriority(7);
            int count = 0;
            sleep(5); 
            for (int i = 0; i < 30; i++)
            {
                count++;
            }
            // printf("PARENT\n");
            exit(0);
        }
    } else {
        wait(0); 
        
    }

    return 0;
}

