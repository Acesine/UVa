#include <iostream>
#include <fstream>

using namespace std;

unsigned int reverseInt(unsigned int N)
{
    unsigned int n = N;
    unsigned int m = 0;
    while(n)
    {
        unsigned int a = n%10;
        m *= 10;
        m += a;
        n /= 10;
    }
    return m;
}

int main()
{
    ifstream input("data.in");
    int T;
    input>>T;
    while(T--)
    {
        unsigned int N;
        input>>N;
        int count=0;
        unsigned int rvs = reverseInt(N);
        while(rvs!=N)
        {
            N+=rvs;
            count++;
            rvs = reverseInt(N);
        }
        cout<<count<<" "<<rvs<<endl;

    }
    return 0;
}
