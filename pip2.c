#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 64
int main(int argc, char const *argv[])
{
    int mj;
    unsigned int a[5];
    mkfifo(12345, S_IRUSR | S_IWUSR);
    mj=open(12345, O_WRONLY);
    write(mj,12345,10);
    close(mj);
    return 0;
}
