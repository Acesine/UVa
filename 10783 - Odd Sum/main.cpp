#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    int T;
    input>>T;
    for(int c=1;c<=T;c++)
    {
        int a,b;
        input>>a>>b;
        a = (a%2==1)? a : a+1;
        b = (b%2==1)? b : b-1;
        int sum = 0;
        if(a<=b)
        {
            sum = (a+b)*(b-a+2)/4;
        }
        cout<<"Case "<<c<<": "<<sum<<endl;
    }
    return 0;
}
