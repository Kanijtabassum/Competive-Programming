
#include<string.h>
#include<stdio.h>

void DistinctList(int arr[],int len)
{

    // code goes here


    int i,cnt;

    for(i=0;i<len;i++)
    {

        cnt=0;
        for(int j=0;j<len;j++)
        {
                if(arr[i] == arr[j])
                {
                   cnt++;
                }
        }
        if(cnt==1)
            printf("%d",arr[i]);


    }


}

int main()
{
    int A[]={1,7,3,1,4,4,5};

    int len= sizeof(A)/sizeof(int);

    DistinctList(A,len);
    return 0;

}


