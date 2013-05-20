#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    int T;
    input>>T;
    int votes1 = 0;
    int votes2 = 0;
    int v[20];
    int power[20];
    int totalvotes = 0;
    while(T--)
    {
        int P;
        input>>P;
        totalvotes = 0;
        memset(v,0,20*sizeof(int));
        memset(power,0,20*sizeof(int));
        for(int i=0;i<P;i++)
        {
            input >> v[i];
            totalvotes += v[i];
        }
        int half = totalvotes/2;
        for(int k = 0;k<(1<<P);k++)
        {
            votes1 = 0;
            for(int i=0;i<P;i++)
            {
                if((k & (1<<i)) > 0)
                    votes1 += v[i];
            }
            if(votes1>half)
            {
                for(int i=0;i<P;i++)
                {
                    if((k & (1<<i)) > 0)
                    {
                        if(votes1-v[i] <= half)
                            power[i] ++;
                    }
                }
            }

        }
        for(int i=0;i<P;i++)
        {
            cout<<"party "<<i+1<<" has power index "<<power[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
