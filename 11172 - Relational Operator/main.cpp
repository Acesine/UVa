#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    int T;
    input>>T;
    while(T--)
    {
        int a,b;
        input>>a>>b;
        if(a<b)
            cout<<"<"<<endl;
        else if(a>b)
            cout<<">"<<endl;
        else
            cout<<"="<<endl;
    }
    return 0;
}
