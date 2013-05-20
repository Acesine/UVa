#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data");
    string s,t;
    while(cin>>s>>t)
    {
        int s_len = s.length();
        int t_len = t.length();
        int j=0,i=0;
        while(i<s_len && j<t_len)
        {
            while(t[j] != s[i] && t_len-j>=s_len-i) j++;
            if(t_len-j<s_len-i)
                break;
            if(t[j] == s[i])
            {
                j++;
                i++;
            }
        }
        if(i == s_len)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}
