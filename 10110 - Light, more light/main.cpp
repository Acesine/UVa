#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    unsigned int N;
    input>>N;
    while(N)
    {
        unsigned int s = sqrt(N);
        if(s*s==N)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        input>>N;
    }
    return 0;
}
