#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
//add the rest of the system headers
#include <sys/types.h> //for wait


int main(void)
{
    int i = 0;

    while (fork() && i < 5) 
    //remember, child returns 0, parent returns child pid
    {
        wait(NULL);
        printf("Yo!");
        i++;
    }
    printf("%d", i);
    return 0;
    
}



/* ANSWERS TO PART 0
 * Missing header: <sys/types.h> for wait
 * Output (#2-4): 0Yo!1Yo!Yo!2Yo!Yo!Yo!3Yo!Yo!Yo!Yo!4Yo!Yo!Yo!Yo!Yo!5Yo!Yo!Yo!Yo!Yo!5
 * Output (#5-7):  
[Detaching after fork from child process 1624034]
0[Detaching after fork from child process 1624035]
Yo!1[Detaching after fork from child process 1624036]
Yo!Yo!2[Detaching after fork from child process 1624037]
Yo!Yo!Yo!3[Detaching after fork from child process 1624038]
Yo!Yo!Yo!Yo!4[Detaching after fork from child process 1624039]
Yo!Yo!Yo!Yo!Yo!5Yo!Yo!Yo!Yo!Yo!5[Inferior 1 (process 1624030) exited normally]
 * 8. since "Yo!" is sent to stdout, it is buffered and is not flushed until buffer is full or program ends.
 * The children are created quickly and copy the buffer, so they gain an increasing amount of "Yo!"s in their buffer.
 * When the children exit, they flush their buffer to stdout, which is why we see multiple "Yo!"s printed at once.
 */