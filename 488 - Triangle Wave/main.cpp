#include <iostream>
//#include <fstream>
using namespace std;

void genWave(int A)
{
    for(int i=1;i<=A;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
    for(int i=A-1;i>=1;i--)
    {
        for(int j=0;j<i;j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
}
int main()
{
//    ifstream input("data.in");
    int T;
    cin>>T;
    while(T--)
    {
        int A,F;
        cin>>A>>F;
        while(F--)
        {
            genWave(A);
            if(F>=1)
                cout<<endl;
        }
        if(T>=1)
            cout<<endl;
    }
    return 0;
}
