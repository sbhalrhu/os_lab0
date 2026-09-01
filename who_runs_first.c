#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#define ITERATIONS 1000
#define SLEEP 0.1 

int main(void)
{
    char parentText[] = "parent";
    char childText[] = "child";
    char newLine[] = "\n";

    for (int i = 0; i<ITERATIONS; i++) 
    {
        pid_t pid = fork();
        if (pid) {
            
            sleep(SLEEP); 
            write(STDOUT_FILENO, parentText, sizeof(parentText)-1);
            
            wait(NULL);
        } else {
            sleep(SLEEP);
            write(STDOUT_FILENO, childText, sizeof(childText)-1);
            
            return 0;
        }
        /*write(STDOUT_FILENO, newLine, sizeof(newLine)-1);*/
        printf("\n");
    }
    return 0;  
}

/* printf with a flush: parentchild mostly
 * printf without a flush: childparent entirely
 * write: parentchild mostly
 * sleep: parentchild mostly; causes program to run much slower
 *
*/