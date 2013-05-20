#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int findTheKth(int *arr,int k,int N)
{
    int pivot = arr[0];
    int p=1,q=N-1;
    while(p<=q && p<N && q>=0)
    {
        while(arr[p]<=pivot && p<N) p++;
        while(arr[q]>pivot && q>=0) q--;
        if(p>=q) break;
        int tmp = arr[p];
        arr[p] = arr[q];
        arr[q] = tmp;
        p ++;
        q --;
    }
    int t = arr[p-1];
    arr[p-1] = pivot;
    arr[0] = t;
    int r;
    if(p==k)
        r = pivot;
    else if(p>k)
    {
        r = findTheKth(arr,k,p);
    }
    else
    {
        r = findTheKth(arr+p,k-p,N-p);
    }

    return r;
}

int main()
{
    int T;
    scanf("%d",&T);
    int location[500];
    while(T--)
    {
        int N;
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&location[i]);
        }
        int mid = (N+1) / 2;
        int s = findTheKth(location,mid,N);
        int sum = 0;
        for(int i=0;i<mid;i++)
        {
            sum += s-location[i];
        }
        for(int i=mid;i<N;i++)
        {
            sum += location[i] - s;
        }
        printf("%d\n",sum);
    }
    return 0;
}
