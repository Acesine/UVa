#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>

using namespace std;

bool checker[3000];

int main()
{
    ifstream input("data.in");
    int N;
    while(input>>N)
    {
        memset(checker,0,N*sizeof(bool));
        int prev,curr;
        input>>prev;
        for(int i=1;i<N;i++)
        {
            input>>curr;
            int diff = abs(curr-prev);
            checker[diff] = true;
            prev = curr;
        }
        int i;
        for(i=1;i<=N-1;i++)
        {
            if(!checker[i])
                break;
        }
        if(i<=N-1)
            cout<<"Not jolly"<<endl;
        else
            cout<<"Jolly"<<endl;
    }
    return 0;
}
