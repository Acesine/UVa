#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
//    ifstream input("data.in");
    char lines[12][25];
    int blanks[12];
    int N;
    cin>>N;
    cin.get();
    while(N!=0)
    {
        int minb = 26;
        for(int k=0;k<N;k++)
        {
            blanks[k] = 0;
            for(int i=0;i<25;i++)
            {
                cin.get(lines[k][i]);
                if(lines[k][i] == ' ')
                    blanks[k] ++;
            }
            if(blanks[k]<minb)
            {
                minb = blanks[k];
            }
            cin.get();
        }
        int sum = 0;
        for(int k=0;k<N;k++)
        {
            sum += blanks[k] - minb;
        }
        cout<<sum<<endl;
        cin>>N;
    }
    return 0;
}
