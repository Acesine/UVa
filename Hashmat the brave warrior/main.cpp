#include <iostream>

using namespace std;

int main()
{
    long long N1,N2,result;
    while(cin>>N1>>N2)
    {
        result = (N2>=N1)? N2-N1:N1-N2;
        cout<<result<<endl;
    }
    return 0;
}
