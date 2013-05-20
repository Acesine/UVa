#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
//    ifstream input("data.in");
    char lines[100][100];
    int length[100];
    char ch;
    int i=0,j=0;
    int maxl = 0;
    while(cin.get(ch))
    {
        lines[i][j] = ch;
        if(ch == '\n')
        {
            length[i] = j;
            if(j>maxl)
                maxl = j;
            i++;
            j = 0;
            continue;
        }
        j++;
    }
    for(int n=0;n<maxl;n++)
    {
        for(int m=i-1;m>=0;m--)
        {
            if(n<length[m])
            {
                if(lines[m][n] != '\n')
                    cout<<lines[m][n];
            }
            else
                cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}
