#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    bool checker[100];
    while(N!=0 || M!=0)
    {
        memset(checker,1,M*sizeof(bool));
        long long T = 1;
        for(int i=N;i>=N-M+1;i--)
        {
            T *= i;
            for(int j=M;j>=1;j--)
            {
                if(checker[j-1] && T%j==0)
                {
                    T /= j;
                    checker[j-1] = 0;
                }
            }
        }
        cout<<N<<" things taken "<<M<<" at a time is "<<T<<" exactly."<<endl;
        cin>>N>>M;
    }
    return 0;
}
