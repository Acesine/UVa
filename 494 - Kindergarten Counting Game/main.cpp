#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream input("data.in");
    char ch;
    bool flag = false;
    int count = 0;
    while(cin.get(ch))
    {
        if(ch == '\n')
        {
            cout<<count<<endl;
            count = 0;
        }
        if(ch >='a'&&ch<='z' || ch >='A'&&ch<='Z')
        {
            if(!flag)
            {
                count ++;
                flag = true;
            }
            else
                continue;
        }
        else
        {
            if(flag)
            {
                flag = false;
            }
        }
    }
    return 0;
}
