#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

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

// int pid = fork();
// if (pid == 0)
// {
//     // printf("CHILD\n");
//     setPriority(2);
//     int count = 0;
//     for (int i = 0; i < 20000000; i++)
//     {
//         count++;
//     }
//     exit(0);
// }
// else
// {

//     setPriority(7);
//     int count = 0;
//     for (int i = 0; i < 30; i++)
//     {
//         count++;
//     }
//     // printf("PARENT\n");
//     wait(0);
// }

//  int pid = fork();
//     if(pid == 0){
//         int childPid = fork();
//         if(childPid == 0){

//             // printf("GC\n");
//             setPriority(7);
//             int count = 0;
//             for(int i = 0; i  < 20000000; i ++){
//                 count ++;
//             }
//             exit(0);

//         } else {

//             // printf("CHILD\n");
//             setPriority(2);
//             int count = 0;
//             for(int i = 0; i  < 20000000; i ++){
//                 count ++;
//             }
//             wait(0);
//             exit(0);
//         }
//     } else {

//         setPriority(5);
//         int count = 0;
//         sleep(5);
//         for(int i = 0; i  < 30; i ++){
//             count ++;
//         }
//         // printf("PARENT\n");
//         wait(0);
//     }