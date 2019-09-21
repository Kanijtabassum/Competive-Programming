#include<stdio.h>
void primeTime(int num)
{
    int flag=1;
    int i;
    for(i=2;i<num;i++)
    {
        if(num%i==0)
            flag=0;
    }
    if(flag==0)
        printf("false");
    else
        printf("true");
}
int main()
{
    primeTime(5);
    return 0;
}
