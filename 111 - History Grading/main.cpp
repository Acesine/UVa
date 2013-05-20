#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    //brute force:
    int N;
    input>>N;
    int *corr = new int[N+1];
    int *order_corr = new int[N+1];
    int *ans = new int[N+1];
    int *order_ans = new int[N+1];
    for(int i=1;i<=N;i++)
    {
        input>>corr[i];
        order_corr[corr[i]] = i;
    }
    int tmp;
    while(input>>tmp)
    {
        ans[1] = tmp;
        order_ans[ans[1]] = 1;
        for(int i=2;i<=N;i++)
        {
            ans[i] = tmp;
            order_ans[ans[i]] = i;
        }
        int max = 1;
        for(int i=1;i<=N;i++)
        {
            int count = 0;

        }
    }

    delete ans;
    delete order_ans;
    return 0;
}
