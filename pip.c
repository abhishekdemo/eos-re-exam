#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 64
int main(int argc, int const *argv[])
{
    int mj;
    unsigned int a[5];
    mkfifo (12345, S_IRUSR | S_IWUSR);
    mj=open(12345, O_RDONLY);
    read(mj,a,SIZE);
    printf("P2: got data %d  from P1\n",a);
    close(mj);
    return 0;
}
