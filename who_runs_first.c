#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#define ITERATIONS 1000
#define SLEEP 1.0

int main(void)
{
    char parentText[] = "parent";
    char childText[] = "child";
    char newLine[] = "\n";

    for (int i = 0; i<ITERATIONS; i++) 
    {
        pid_t pid = fork();
        if (pid) {
            printf("parent");
            fflush(stdout);
            wait(NULL);
        } else {
            printf("child");
            fflush(stdout);
            return 0;
        }
        printf("\n");
    }
    return 0;  
}