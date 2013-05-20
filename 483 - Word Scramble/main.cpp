#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void strreverse(string &str)
{
    string tmp = str;
    int l = str.length();
    for(int i=0;i<l;i++)
    {
        str[i] = tmp[l-i-1];
    }
}

int main()
{
    ifstream input("data.in");
    string str;
    while(input>>str)
    {
        strreverse(str);
        cout<<str;
        char c;
        input.get(c);
        cout<<c;
    }
    return 0;
}
