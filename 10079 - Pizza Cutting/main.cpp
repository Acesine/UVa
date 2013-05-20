#include <cstdio>

using namespace std;

int main()
{
//    freopen("data.in","r",stdin);
    int N;
    scanf("%d",&N);
    while(N>=0)
    {
        long long cut = N;
        cut = cut*(N+1)/2 + 1;
        printf("%lld\n",cut);
        scanf("%d",&N);
    }
    return 0;
}
