#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
//    ifstream input("data.in");
    int alphabet[26];
    int round;
    cin>>round;
    while(round != -1)
    {
        cout<<"Round "<<round<<endl;
        cin.get();
        //clear alpha:
        for(int i=0;i<26;i++)
        {
            alphabet[i] = 0;
        }
        int remains = 0;
        char tmp;
        cin.get(tmp);
        while(tmp!='\n')
        {
            if(alphabet[tmp-'a'] == 0)
            {
                alphabet[tmp-'a'] = 1;
                remains ++;
            }
            cin.get(tmp);
        }
        cin.get(tmp);
        int wrongguesses = 0;
        while(tmp!='\n')
        {
            if(alphabet[tmp-'a']>0)
            {
                if(alphabet[tmp-'a']==1)
                    remains --;
                if(remains == 0)
                {
                    cout<<"You win."<<endl;
                    break;
                }
                alphabet[tmp-'a'] ++;
            }
            else
            {
                if(alphabet[tmp-'a']==0)
                    wrongguesses ++;
                alphabet[tmp-'a'] -- ;
                if(wrongguesses >= 7)
                {
                    cout<<"You lose."<<endl;
                    break;
                }
            }
            cin.get(tmp);
        }
        if(remains != 0 && wrongguesses < 7)
        {
            cout<<"You chickened out."<<endl;
            cin>>round;
            continue;
        }
        string st;
        getline(cin,st);
        cin>>round;
    }
    return 0;
}
