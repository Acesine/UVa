#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int longAdd(char *num1,int N,char *num2,int M,char *sum)
{
    int carry = 0;
    int i;
    for(i=0;i<N && i<M;i++)
    {
        int a = (num1[i]-'0') + (num2[i]-'0') + carry;
        if(a>=10)
        {
            carry = 1;
            a -= 10;
        }
        else
        {
            carry = 0;
        }
        sum[i] = a+'0';
    }
    while(i<M)
    {
        int a = (num2[i]-'0') + carry;
        if(a>=10)
        {
            carry = 1;
            a -= 10;
        }
        else
        {
            carry = 0;
        }
        sum[i] = a+'0';
        i++;
    }
    while(i<N)
    {
        int a = (num1[i]-'0') + carry;
        if(a>=10)
        {
            carry = 1;
            a -= 10;
        }
        else
        {
            carry = 0;
        }
        sum[i] = a+'0';
        i++;
    }
    if(carry==1)
    {
        sum[i] = '1';
        i++;
    }
    return i;
}

void convert(string &str,char* result)
{
    int k=0;
    for(int i=str.length()-1;i>=0;i--,k++)
    {
        result[k] = str[i];
    }
}

int main()
{
    ifstream input("data.in");
    char adder1[110];
    int N;
    char adder2[110];
    char sum[110];
    int L = 0;
    memset(sum,0,110*sizeof(char));
    memset(adder2,0,110*sizeof(char));
    string str;
    while(1)
    {
        input>>str;
        N = str.length();
        if(str.length() == 1)
        {
            if(str[0] == '0')
                break;
        }
        convert(str,adder1);
        L = longAdd(adder1,N,adder2,L,sum);
        for(int i=0;i<L;i++)
        {
            adder2[i] = sum[i];
        }
    }
    for(int i=L-1;i>=0;i--)
    {
        cout<<sum[i];
    }
    cout<<endl;
    return 0;
}
