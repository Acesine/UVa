#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    int front[10],rear[10];
    vector<double> ratios;
    int F,R;

    while(input>>F>>R)
    {
        ratios.clear();
        for(int i=0;i<F;i++)
        {
            input>>front[i];
        }
        for(int i=0;i<R;i++)
        {
            input>>rear[i];
        }
        for(int i=0;i<F;i++)
        {
            for(int j=0;j<R;j++)
            {
                ratios.push_back(1.0*rear[j]/front[i]);
            }
        }
        sort(ratios.begin(),ratios.end());
        double max_r = 0;
        for(int i=0;i<ratios.size()-1;i++)
        {
            if(ratios[i+1]/ratios[i] > max_r)
                max_r = ratios[i+1]/ratios[i];
        }
        printf("%.2f\n",max_r);
    }
    return 0;
}
