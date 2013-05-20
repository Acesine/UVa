#include <iostream>
#include <string>
#include <fstream>

using namespace std;
unsigned int mapping[31];
void getMapping()
{
    for(int i=0;i<31;i++)
    {
        mapping[i] = (1<<(i+1)) - 1;
    }
}
int main()
{
    ifstream input("data.in");
    getMapping();
    string sb;
    input>>sb;
    while(1)
    {
        if(sb.length() == 1 && sb[0]=='0')
            break;
        int sum = 0;
        int p=0;
        for(int i=sb.length()-1;i>=0;i--,p++)
        {
            sum += (sb[i]-'0')*mapping[p];
        }
        cout<<sum<<endl;
        input>>sb;
    }
    return 0;
}
