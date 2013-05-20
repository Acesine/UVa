#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    int Dur[20];
    int N;
    int T;
    while(input>>N>>T)
    {
        for(int i=0;i<T;i++)
        {
            input>>Dur[i];
        }
        int nearest = N+1;
        int c = -1;
        for(int k=0;k<(1<<T);k++)
        {
            int sum = 0;
            for(int i=0;i<T;i++)
            {
                if((k&(1<<i)) > 0)
                {
                    sum += Dur[i];
                }
            }
            if(N-sum>=0 && N-sum < nearest)
            {
                c = k;
                nearest = N-sum;
            }
        }
        for(int i=0;i<T;i++)
        {
            if((c&(1<<i)) > 0)
            {
                cout<<Dur[i]<<" ";
            }
        }
        cout<<"sum:"<<N-nearest<<endl;
    }
    return 0;
}
