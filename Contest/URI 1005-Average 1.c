#include<stdio.h>
/*
int main()
{
    double a,b, avg;
    scanf("%lf %lf",&a,&b);
    avg=((a*3.5)+b*7.5)/(3.5+7.5);
    printf("MEDIA = %.5lf\n",avg);
    return 0;
}


int main()
{
    int n, mh;
    double  ph,result;
    scanf("%d %d %lf",&n, &mh, &ph);
    result=(ph*mh);
    printf("NUMBER = %d\n",n);
    printf("SALARY = U$ %.2lf\n",result);
    return 0;
}


// URI 1019
int main()
{
    int s,m,h;
    scanf("%d",&s);
    h=s/3600;
    s=s%3600;
    m=s/60;
    s=s%60;

    printf("%d:%d:%d\n",h,m,s);
}
*/

//URI 1020
#include<stdio.h>
int main()
{
    int day,month,year;
    scanf("%d",&day);
    year=day/365;
    day=day%365;
    month=day/30;
    day=day%30;

    printf("%d ano(s)\n",year);
    printf("%d mes(es)\n",month);
    printf("%d dia(s)\n",day);

    return 0;
}
