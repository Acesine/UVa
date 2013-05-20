#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool changebase(string &num1,int base1,string &num2,int base2);

int main(int argc, char **argv)
{
	int base1;
	int base2;
	string num1;
	string num2;
	while(cin>>base1>>base2>>num1)
	{
		num2.clear();
		if(changebase(num1,base1,num2,base2))
		{
			cout<<num1<<" base "<<base1<<" = "<<num2<<" base "<<base2<<endl;
		}
		else
		{
			cout<<num1<<" is an illegal base "<<base1<<" number"<<endl;
		}
	}
	return 0;
}

bool changebase(string &num1,int base1,string &num2,int base2)
{
	long long int temp = 0;
	int digit = 0;
	int length = num1.length();
	for(int i=0;i<num1.length();i++)
	{
		if(num1[i] >= '0' && num1[i]<= '9')
		{
			digit = num1[i] - '0';
			if(digit >= base1)
			{
				return false;
			}
			else
			{
				temp += digit * pow(base1,length-1-i);
			}
		}
		else
		{
			if(num1[i] >= 'A' && num1[i]<= 'F')
			{
				digit = num1[i] - 'A' + 10;
				if(digit >= base1)
				{
					return false;
				}
				else
				{
					temp += digit * pow(base1,length-1-i);
				}
			}
			else
			{
				return false;
			}
		}
	}
	char c;
	int remainder;
	while(temp / base2 || temp % base2)
	{
		remainder = temp % base2;
		(remainder >= 0 && remainder <= 9)? c = '0' + remainder : c = 'A'+remainder-10;
		num2.insert(num2.begin(),c);
		temp /= base2;
	}
	if(num2.empty())
	{
		num2.insert(num2.begin(),'0');
	}
	return true;
}