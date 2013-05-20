#include <iostream>
using namespace std;

struct bigInt
{
	char data[65];
};

int checkLength(struct bigInt &bn)
{
	int i;
	for(i=0;bn.data[i] != '\0';i++);
	return i;
}

void printBigInt(struct bigInt &bn)
{
	int i;
	for(i=0;bn.data[i] != '\0';i++);
	i--;
	while(i>=0)
	{
		cout<<bn.data[i];
		i--;
	}
	
}

void addBigInt(struct bigInt &adder1,struct bigInt &adder2,struct bigInt &sum)
{
	int i = 0;
	bool carryflag = false;
	int temp = 0;
	for(i=0;adder1.data[i] != '\0' && adder2.data[i] != '\0';i++)
	{
		temp = adder1.data[i] - '0' + adder2.data[i] - '0';
		if(carryflag)
		{
			temp ++;
			carryflag = false;
		}
		if(temp >= 10)
		{
			carryflag = true;
		}
		sum.data[i] = temp % 10 + '0';
	}
	if(adder1.data[i] == '\0')
	{
		while(adder2.data[i] != '\0')
		{
			temp = adder2.data[i] - '0';
			if(carryflag)
			{
				temp ++;
				carryflag = false;
			}
			if(temp >= 10)
			{
				carryflag = true;
			}
			sum.data[i] = temp % 10 + '0';
			i++;
		}
	}
	else
	{
		while(adder1.data[i] != '\0')
		{
			temp = adder1.data[i] - '0';
			if(carryflag) 
			{
				temp ++;
				carryflag = false;
			}
			if(temp >= 10) 
			{
				carryflag = true;
			}
			sum.data[i] = temp % 10 + '0';
			i++;
		}
	}
	if(carryflag)
	{
		sum.data[i] = '1';
		i++;
	}
	sum.data[i] = '\0';
}

void bigIntCp(struct bigInt &num1,struct bigInt &num2)
{
	int i;
	for(i=0;num1.data[i] != '\0';i++)
	{
		num2.data[i] = num1.data[i];
	}
	num2.data[i] = '\0';
}

int main(int argc, char **argv)
{
	
	int LENGTH = 1000;
	bigInt current[LENGTH];
	bigInt previous[LENGTH];
	cout<<1<<endl;
	previous[0].data[0] = '1';
	previous[0].data[1] = '\0';
	int count = 2;
	bool loopflag = true;
	while(loopflag && count < LENGTH)
	{
		current[0].data[0] = '1';
		current[0].data[1] = '\0';
		printBigInt(current[0]);
		cout<<" ";
		for(int i=1;i<count-1;i++)
		{
			addBigInt(previous[i-1],previous[i],current[i]);
			printBigInt(current[i]);
			cout<<" ";
			if(checkLength(current[i]) >= 61)
			{
				loopflag = false;
			}
		}
		current[count-1].data[0] = '1';
		current[count-1].data[1] = '\0';
		printBigInt(current[count-1]);
		cout<<endl;
		for(int j=0;j<count;j++)
		{
			bigIntCp(current[j],previous[j]);
		}
		count++;
	}
	
	return 0;
}