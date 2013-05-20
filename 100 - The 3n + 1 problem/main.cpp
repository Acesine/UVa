#include <iostream>
using namespace std;

int main(void)
{
	int a,b,max,n,count;
	while(cin >>a>>b)
	{
//		cout << a <<" "<< b <<" ";
		if(a>b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		if(a<=0)
			break;
		if(b>=1000000)
			break;
		max = 0;
		for(int i=a;i<=b;i++)
		{
			n = i;
			count = 1;
			while(1)
			{
				if(n == 1)
					break;
				else
				{
					if(n%2)
					{
						n = 3*n+1;
					}
					else
					{
						n /= 2;
					}
				}
				count++;
			}
			if(count > max)
				max = count;
		}
		cout<< max <<endl;
	}
	return 0;
}
