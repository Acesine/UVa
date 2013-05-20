#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int findMax(int *arr,int N)
{
    int m = arr[0];
    int c = arr[0];
    for(int i=1;i<N;i++)
    {
        if(c+arr[i]>arr[i])
        {
            c = c+arr[i];
        }
        else
            c = arr[i];
        if(c>m)
            m = c;
    }
    return m;
}

int main()
{
    ifstream input("data.in");
    int dp[100];
    int M[100][100];
    int N;
    input>>N;
    int sum = -128;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            input>>M[i][j];
        }
    }
    for(int i=0;i<N;i++)
    {
        memset(dp,0,N*sizeof(int));
        for(int j=i;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                dp[k] += M[j][k];
            }
            int tmp = findMax(dp,N);
            if(tmp>sum)
                sum = tmp;
        }
    }
    cout<<sum<<endl;
    return 0;
}
