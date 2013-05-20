#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    char c;
    bool flag = false;
    while(input.get(c))
    {
        if(c=='"')
        {
            if(!flag)
            {
                cout<<"``";
                flag = true;
            }
            else
            {
                cout<<"''";
                flag = false;
            }
        }
        else
        {
            cout<<c;
        }
    }
    return 0;
}
