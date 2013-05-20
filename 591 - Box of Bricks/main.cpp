#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    int h[50];
    int N;
    input>>N;
    int s = 1;
    while(N)
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            input>>h[i];
            sum += h[i];
        }
        int avg = sum/N;
        int moves = 0;
        for(int i=0;i<N;i++)
        {
            int m = h[i]-avg;
            if(m>0)
            {
                moves += m;
            }
        }
        cout<<"Set #"<<s<<endl;
        cout<<"The minimum number of moves is "<<moves<<"."<<endl;
        cout<<endl;
        s++;
        input>>N;
    }
    return 0;
}
