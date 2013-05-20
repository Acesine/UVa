#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.in");
    int T;
    input>>T;
    vector<int> nums;
    for(int c=1;c<=T;c++)
    {
        nums.clear();
        int N;
        input>>N;
        for(int i=0;i<N;i++)
        {
            int tmp;
            input>>tmp;
            nums.push_back(tmp);
        }

    }
    return 0;
}
