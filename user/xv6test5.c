#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

//process with a sleep call and useryeild
int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        setPriority(7); 
        int childFork = fork();
        if (!childFork)
        {
            int count = 0; 
            for (int i = 0; i < 200; i++)
            {
                if(i % 4 == 0){
                    userYield();
                    userYield(); 
                } else {
                    count ++; 
                }
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
                int k = 0;
                while((5+k) >= 50){
                    k++;
                }
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
