#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
//    ifstream input("data.in");
    char ch;
    int sum = 0;
    while(cin.get(ch))
    {
        sum = 0;
        if(ch == '\n' || ch == '!')
        {

            cout<<endl;
            continue;
        }
        while(ch>='0'&&ch<='9')
        {
            sum += ch-'0';
            cin.get(ch);
        }
        for(int i=0;i<sum;i++)
        {
            if(ch == 'b')
                cout<<" ";
            else
            {
                cout<<ch;
            }
        }
    }
    return 0;
}
