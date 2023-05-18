#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
    int pid = fork(); 
    if(pid == 0){
        int childPid = fork();
        if(childPid == 0){
            printf("grandchild\n");

            exit(0);  
        } else {        
            printf("child\n");

            wait(0); 
            exit(0);  
        }
    } else {
        printf("parent\n");
        wait(0);  
    }
    return 0; 
}