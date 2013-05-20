#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    double rate[20][20];
    double trans[20][20][20];
    int prev[20][20][20];
    double profit[20];
    int N;
    while(input>>N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(j == i)
                    rate[i][j] = 1;
                else
                    input>>rate[i][j];
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                trans[0][i][j] = (i==j)? 1:0;
                prev[0][i][j] = i;
            }
        }
        bool stopflag = false;
        int source = -1;
        int sink = -1;
        int k;
        for(k=1;k<N;k++)
        {
            for(int i=0;i<N;i++)
            {
                profit[i] = 0;
                for(int j=0;j<N;j++)
                {
                    double temp_v = -1;
                    for(int n=0;n<N;n++)
                    {
                        if(trans[k-1][i][n]*rate[n][j] > temp_v)
                        {
                            temp_v = trans[k-1][i][n]*rate[n][j];
                            prev[k][i][j] = n;
                        }
                    }
                    trans[k][i][j] = temp_v;
                    if(trans[k][i][j] * rate[j][i] > profit[i])
                    {
                        profit[i] = trans[k][i][j] * rate[j][i];
                        if(profit[i]-1 > 0.01)
                        {
                            stopflag = true;
                            source = i;
                            sink = j;
                            break;
                        }
                    }
                }
                if(stopflag)
                    break;
            }
            if(stopflag)
                break;
        }
        vector<int> chain;
        chain.push_back(source);
        for(int i=k;i>=0;i--)
        {
            chain.push_back(sink);
            sink = prev[i][source][sink];
        }
        if(source == -1)
            cout<<"no arbitrage sequence exists"<<endl;
        else
        {
            cout<<chain[chain.size()-1]+1;
            for(int i=chain.size()-2;i>=0;i--)
            {
                cout<<" "<<chain[i]+1;
            }
            cout<<endl;
        }
    }

    return 0;
}
