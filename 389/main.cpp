#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{
	string input;
	string output;
	int base1;
	int base2;
	while(cin>>input>>base1>>base2)
	{
		int temp = 0;
		int count = 0;
		for(int i=input.length()-1;i>=0;i--)
		{
			if(input[i]>='0'&&input[i]<='9')
			{
				temp += (input[i]-'0')*pow(base1,count);
			}
			else
			{
				temp += (input[i]-'A'+10)*pow(base1,count);
			}
			count ++;
		}
		if(temp >= pow(base2,7))
		{
			output = "ERROR";
		}
		else
		{
			if(temp == 0)
			{
				output = '0';
			}
			else
			{
				while(temp)
				{
					char tpchar;
					int residue = temp % base2;
					tpchar = (residue<10)? '0'+residue : 'A'+residue-10;
					output.insert(output.begin(),tpchar);
					temp = temp/base2;
				}
			}
		}
		cout << setiosflags(ios_base::right)<<setw(7)<<output<<endl;
		input.clear();
		output.clear();
	}
	return 0;
}
