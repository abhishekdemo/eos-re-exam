#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 64
int main(int argc, int const *argv[])
{   int a[5];
    int pfd[2];
    pid_t id;
    pipe(pfd);
    id=fork();
    if(0==id)
    {
        printf("Child\n");
        close(pfd[1]);
        read(pfd[0],a,5);
        printf("Child got data: %d\n",a);
        close(pfd[0]);
    }
    else
    {
            printf("Parent:\n");
            close(pfd[0]);
            write(pfd[1],12345,5);
            close(pfd[1]);
    }
    return 0;
}