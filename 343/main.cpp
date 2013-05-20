#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int change2base10(string &num,int base);
int main(int argc, char **argv)
{
	string num1,num2;
	int temp1,temp2;
	bool flag = false;
	int i,j;
	while(cin>>num1>>num2)
	{
		flag = false;
		for(i=2;i<=36;i++)
		{
			temp1 = change2base10(num1,i);
			if(temp1 == -1)
				continue;
			for(j=2;j<=36;j++)
			{
				temp2 = change2base10(num2,j);
				if(temp2 == -1)
					continue;
				if(temp2 == temp1)
				{
					flag = true;
					break;
				}
			}
			if(flag == true)
				break;
		}
		if(flag == true)
		{
			cout<<num1<<" (base "<<i<<") = "<<num2<<" (base "<<j<<")"<<endl;			
		}
		else
		{
			cout<<num1<<" is not equal to "<<num2<<" in any base 2..36"<<endl;
		}
	}
	return 0;
}

int change2base10(string& num,int base)
{
	string::iterator it;
	int temp = 0;
	int count = 0;
	int length = num.length();
	int digit;
	
	for(it=num.begin();it<num.end();it++)
	{
		((*it)>='0'&&(*it)<='9')? digit = (*it)-'0' : digit = (*it)-'A'+10;
		if(digit >= base)
		{
			return -1;
		}
		temp += digit*pow(base,length-1-count);
		count ++;
	}
	return temp;
}