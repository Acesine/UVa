/*
#include <iostream>

using namespace std;

unsigned int dp[1500];

int min3(int a,int b,int c)
{
    return (a<b)? (a<c)? a:c : (b<c)? b:c;
}

int main()
{
    dp[0] = 1;
    int p2 = 0,p3 = 0,p5 = 0;
    for(int i=1;i<1500;i++)
    {
        dp[i] = min3(2*dp[p2],3*dp[p3],5*dp[p5]);
        if(dp[i] == 2*dp[p2])
            p2++;
        if(dp[i] == 3*dp[p3])
            p3++;
        if(dp[i] == 5*dp[p5])
            p5++;
    }
    cout<<"The 1500'th ugly number is "<<dp[1499]<<"."<<endl;
    return 0;
}
*/
#include<stdio.h>
int main()
{
    printf("The 1500'th ugly number is 859963392.\n");
    return 0;
}
