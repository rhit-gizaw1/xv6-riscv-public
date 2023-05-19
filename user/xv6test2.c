#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int pid;
    int count = 0;
    printf("Parent process with PID = %d\n", getpid());

    for (int i = 0; i < 10; i++)
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
    printf("Count is %d\n", count);

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