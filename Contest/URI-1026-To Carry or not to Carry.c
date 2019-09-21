#include<stdio.h>
int main()
{
    unsigned A,B;
    while(2==scanf("%u %u",&A,&B))
    {
        printf("%u\n",(A^B));
    }
    return 0;
}
