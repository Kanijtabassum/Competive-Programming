#include<stdio.h>
void fizzBuzz(int num)
{
    int i,flag=0;

    for(i=1;i<=num;i++){

        if(flag==0)
            flag=1;
        else
            printf(" ");

        if(i%3==0 && i%5==0)
            printf("FizzBuzz");
        else if(i%3==0)
            printf("Fizz");
        else if(i%5==0)
            printf("Buzz");
        else
            printf("%d",i);
    }
}
int main()
{

    fizzBuzz(12);
    printf("\n");

    return 0;
}
