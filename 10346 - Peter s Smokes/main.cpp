#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int a,b;
    while(scanf("%d %d",&a,&b) != EOF)
    {
        int sum = 0;
        int d = 0;
        while(a)
        {
            int olda = a;
            int oldd = d;
            sum += a;
            d = (olda+oldd)%b;
            a = (olda+oldd)/b;
        }
        printf("%d\n",sum);

    }
    return 0;
}
