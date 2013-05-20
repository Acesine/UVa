#include <iostream>
//#include <fstream>
#include <string>
using namespace std;

int main()
{
//    ifstream input("data.in");
    string strin,strout;
    while(getline(cin,strin))
    {
        strout.clear();
        for(int i=0;i<strin.length();i++)
        {
            strout.push_back(strin[i]-7);
        }
        cout<<strout<<endl;
    }
    return 0;
}
