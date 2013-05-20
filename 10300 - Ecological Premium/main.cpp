#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int sum = 0;
        while(N--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            sum += a*c;
        }
        cout<<sum<<endl;
    }
    return 0;
}
