#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
    int pid = fork(); 
    if(pid == 0){
        int childPid = fork();
        if(childPid == 0){

            setPriority(7); 
            printf("grandchild\n");
            int count = 0; 
            for(int i = 0; i  < 200000000000; i ++){
                count ++; 
            }
            exit(0);  

        } else {        

            printf("child\n");
            setPriority(2); 
            int count = 0; 
            for(int i = 0; i  < 200000000000; i ++){
                count ++; 
            }
            wait(0); 
            exit(0);  
        }
    } else {

        setPriority(5); 
        int count = 0; 
        sleep(5); 
        for(int i = 0; i  < 30; i ++){
            count ++; 
        }
        printf("parent\n");
        wait(0);  
    }
    return 0; 
}