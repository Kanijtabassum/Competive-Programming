#include<stdio.h>
int main()
{
    float X,Y;
    scanf("%f %f",&X,&Y);
    if(X>0)
    {
        if(Y>0)
            printf("Q1\n");
        else if(Y<0)
            printf("Q4\n");
        else
            printf("Eixo X\n");
    }
    else if(X<0)
    {
        if(Y>0)
            printf("Q2\n");
        else if(Y<0)
            printf("Q3\n");
        else
            printf("Eixo X\n");
    }
    else
    {
        if(0==Y)
            printf("Origem\n");
        else
            printf("Eixo Y\n");
    }

    return 0;

}
