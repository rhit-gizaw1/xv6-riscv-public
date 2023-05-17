#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int count2 = 0;
void function1()
{
    int i = 0;
    while (i < 1000000)
    {
        i++;
    }
    printf("in function 1\n");
}

void function2()
{
    for (int i = 0; i < 10; i++)
    {
        count2 = count2 + 1;
    }
    printf("in function 2\n");
}

void function3()
{
    for (int i = 0; i < 10; i++)
    {
        count2 = count2 + 1;
    }
    printf("in function 3\n");
}

int main(int argc, char *argv[])
{
    printf("here\n");
    exit(0);
}