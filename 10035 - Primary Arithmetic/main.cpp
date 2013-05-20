#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    unsigned int a,b;
    input>>a>>b;
    while(a!=0 || b!=0)
    {
        int count = 0;
        int carry = 0;
        while(a!=0 && b!=0)
        {
            int m = a%10;
            int n = b%10;
            if(m+n+carry>=10)
            {
                count++;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            a /= 10;
            b /= 10;
        }
        if(a!=0)
        {
            while(a!=0)
            {
                int m = a%10;
                if(m+carry>=10)
                {
                    count++;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                a /= 10;
            }
        }
        if(b!=0)
        {
            while(b!=0)
            {
                int n = b%10;
                if(n+carry>=10)
                {
                    count++;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                b /= 10;
            }
        }
        if(count == 0)
            cout<<"No carry operation."<<endl;
        else if(count == 1)
            cout<<"1 carry operation."<<endl;
        else
            cout<<count<<" carry operations."<<endl;
        input>>a>>b;
    }
    return 0;
}
