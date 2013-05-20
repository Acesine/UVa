#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    int grades[1000];
    int T;
    input>>T;
    while(T--)
    {
        int N;
        input>>N;
        double sum = 0;
        for(int i=0;i<N;i++)
        {
            input>>grades[i];
            sum += grades[i];
        }
        double avg = sum/N;
        int count = 0;
        for(int i=0;i<N;i++)
        {
            if(grades[i]>avg)
            {
                count++;
            }
        }
        printf("%.3f%\n",1.0*count/N*100);
    }
    return 0;
}
