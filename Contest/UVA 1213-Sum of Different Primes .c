#include<stdio.h>
#define SIZEN 1122
#define SIZE_K 15
#define PRIME_SET 189
int dp[SIZEN][SIZE_K][PRIME_SET];
int prime[PRIME_SET] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129};
int n;
int k;

int solveCase(int i, int kN, int make)
{
    int left,right;

    if (make > 0 && kN == 0) return 0;
    if (kN == 0 && make == 0)
        return 1;

   if (make < 0 || kN < 0) return 0;
    if (prime[i] > make) return 0;


    if(dp[make][kN][i]!=-1)
        return dp[make][kN][i];

   left=solveCase(i+1,kN,make);
   if(make-prime[i]>=0)
       right=solveCase(i+1,kN-1,make-prime[i]);
  else
        right=0;
    return dp[make][kN][i]=left+right;


}
int main()
{
   int i,j,z,count;
    for(i=0;i<SIZEN;i++)
            for(j=0;j<SIZE_K;j++)
                for(z=0;z<PRIME_SET;z++)
                    dp[i][j][z]=-1;

        freopen("h.txt","r",stdin);
    while(scanf("%d%d",&n,&k) && n && k)
    {

        printf("%d\n",solveCase(0,k,n));
    }
    return 0;

}
