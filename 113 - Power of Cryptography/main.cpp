#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    ifstream input("data.in");
    double n,p;
    double k;
    while(input>>n>>p)
    {
        k = exp(log(p)/n);
        printf("%.0f\n",k);
    }
    return 0;
}
