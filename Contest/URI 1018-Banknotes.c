#include<stdio.h>
#include <math.h>
/*
 int main()
 {
     int N;
     scanf("%d",&N);
     printf("%d\n",N);
     printf("%d nota(s) de R$ 100,00\n",N/100);
     N=N%100;
     printf("%d nota(s) de R$ 50,00\n",N/50);
     N=N%50;
     printf("%d nota(s) de R$ 20,00\n",N/20);
     N=N%20;
     printf("%d nota(s) de R$ 10,00\n",N/10);
     N=N%10;
     printf("%d nota(s) de R$ 5,00\n",N/5);
     N=N%5;
     printf("%d nota(s) de R$ 2,00\n",N/2);
     N=N%2;
     printf("%d nota(s) de R$ 1,00\n",N/1);

     return 0;
 }


int main()
{
    int t, s,u;
    scanf("%d",&t);
    scanf("%d",&s);
    printf("%.3f\n",(s*t)/12.00);
    return 0;
}
*/

int main()
{
    double a,b,c;
    double r1,r2,d;
    freopen("h.txt","r",stdin);
    scanf("%lf %lf %lf",&a,&b,&c);
    d=(pow(b,2)-(4*a*c));

    if(a==0 || d<0 )
        printf("Impossivel calcular\n");
    else{
        r1 = (-b + sqrt(d) )/(2*a);

        r2 = (-b - sqrt(d) )/(2*a);
        printf("R1 = %.5lf\n",r1);
        printf("R2 = %.5lf\n",r2);
    }
    return 0;
}
