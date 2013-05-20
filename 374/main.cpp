#include <iostream>

using namespace std;
long bigmod(long b, long p, long m)
{
	if(p == 0)
		return 1;
	if(p%2 == 0)
	{
		long temp = bigmod(b,p/2,m);
		return (temp*temp)%m;
	}
	else
	{
		return ((b%m)*bigmod(b,p-1,m))%m;
	}
}
int main(int argc, char **argv)
{
	long b,p,m;
	long r;
	while(cin>>b>>p>>m)
	{
		r = bigmod(b,p,m);
		cout<<r<<endl;
	}
	return 0;
}
