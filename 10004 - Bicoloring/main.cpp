#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    int N;
    input>>N;
    vector<int> adjlist[200];
    int level[200];
    while(N)
    {
        for(int i=0;i<N;i++)
            level[i] = -1;
        int L;
        input>>L;
        for(int i=0;i<N;i++)
            adjlist[i].clear();
        for(int i=0;i<L;i++)
        {
            int a,b;
            input>>a>>b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        queue<int> nodequeue;
        nodequeue.push(0);
        level[0] = 0;
        int flag = true;
        while(nodequeue.size())
        {
            int current = nodequeue.front();
            nodequeue.pop();
            for(int i=0;i<adjlist[current].size();i++)
            {
                if(level[adjlist[current][i]] == level[current])
                {
                    flag = false;
                    break;
                }
                if(level[adjlist[current][i]] == -1)
                {
                    level[adjlist[current][i]] = level[current]+1;
                    nodequeue.push(adjlist[current][i]);
                }
            }
            if(!flag)
            {
                break;
            }
        }
        if(flag)
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
        input>>N;
    }
    return 0;
}
