#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct alphabet
{
    char ch;
    int freq;
};
bool cmpfunc(alphabet a,alphabet b)
{
    if(a.freq>b.freq)
        return true;
    else if(a.freq==b.freq)
    {
        return a.ch<b.ch;
    }
    else
        return false;
}
int freq[26];
int main()
{
    ifstream input("data.in");
    int N;
    input>>N;
    char c;
    vector<alphabet> myalpha;
    while(input.get(c))
    {
        if(c>='a'&&c<='z')
        {
            freq[c-'a'] ++;
        }
        if(c>='A'&&c<='Z')
        {
            freq[c-'A'] ++;
        }
    }
    for(int i=0;i<26;i++)
    {
        alphabet tmp;
        tmp.ch = 'A' + i;
        tmp.freq = freq[i];
        myalpha.push_back(tmp);
    }
    sort(myalpha.begin(),myalpha.end(),cmpfunc);
    for(int i=0;i<26;i++)
    {
        if(myalpha[i].freq>0)
        {
            cout<<myalpha[i].ch<<" "<<myalpha[i].freq<<endl;
        }
    }
    return 0;
}
