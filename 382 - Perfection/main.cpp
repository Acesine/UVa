#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>

using namespace std;

int isPerfection(int N)
{
    if(N == 1)
        return 2;
    int sum = 1;
    int sqr = sqrt(N);
    for(int i=2;i<=sqr;i++)
    {
        if(N%i==0)
        {
            sum += i;
            if(N/i!=i)
                sum+=N/i;
        }
    }
    if(sum == N)
        return 1;
    if(sum<N)
        return 2;
    if(sum>N)
        return 3;
}

int main()
{
    ifstream input("data.in");
    cout<<"PERFECTION OUTPUT"<<endl;
    int N;
    input>>N;
    while(N)
    {
        printf("%5d  ",N);
        int a = isPerfection(N);
        if(a==1)
        {
            cout<<"PERFECT"<<endl;
        }
        if(a==2)
        {
            cout<<"DEFICIENT"<<endl;
        }
        if(a==3)
        {
            cout<<"ABUNDANT"<<endl;
        }
        input>>N;
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
