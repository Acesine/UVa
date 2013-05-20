#include <iostream>

using namespace std;
/*
int fibmod(long long n, int mask)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return (1&mask);
	int temp1 = fibmod((n+1)/2,mask);
	int temp2 = fibmod((n-1)/2,mask);
	if(n % 2)
	{
		return (((temp1*temp1) & mask) + ((temp2*temp2) & mask)) & mask;
	}
	else
	{
		return (((temp1*temp1) & mask) + ((2*temp1*temp2) & mask)) & mask;
	}
}
*/
/*
int fibmod(long long n, int mask)
{
	int i = 1;
	int j = 0;
    int k = 0;
	int h = 1;
	int t;
	while (n > 0)
	{
          if (n%2)
		  {
             t = (j*h) & mask;
             j = (i*h + j*k + t) & mask;
             i = (i*k + t) & mask;
		  }
          t = (h*h) & mask;
          h = (2*k*h + t) & mask;
          k = (k*k + t) & mask;
          n = n/2;
	}
	return j & mask;
}
*/

void multiply(long long F[2][2], long long M[2][2],int mask);
void power(long long F[2][2], long long n,int mask); 
//function that returns nth Fibonacci number
int fibmod(long long n,int mask)
{
  long long F[2][2] = {{1,1},{1,0}};
  if(n == 0)
    return 0;
  power(F, n-1,mask);
  return F[0][0];
}
 
//Optimized version of power() in method 4
void power(long long F[2][2], long long n,int mask)
{
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2,mask);
  multiply(F, F,mask);
 
  if( n%2 != 0 )
     multiply(F, M,mask);
}
 
void multiply(long long F[2][2], long long M[2][2],int mask)
{
  long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x & mask;
  F[0][1] = y & mask;
  F[1][0] = z & mask;
  F[1][1] = w & mask;
}
int main()
{
	long long n;
	int m;
	int mask;
	while(cin>>n>>m)
	{
		mask = (1<<m)-1;
		cout<<fibmod(n,mask)<<endl;
	}
	return 0;
}
