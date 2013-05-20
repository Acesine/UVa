#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct{
    int num;
    vector<int> sizes;
} Box;

bool nests(Box b1,Box b2)
{
    //sizes of b1, b2 are sorted
    for(int i=0;i<b1.sizes.size();i++)
    {
        if(b1.sizes[i] >= b2.sizes[i])
            return false;
    }
    return true;
}

bool comp(Box b1,Box b2)
{
    //sizes of b1, b2 are sorted
    for(int i=0;i<b1.sizes.size();i++)
    {
        if(b1.sizes[i] > b2.sizes[i])
            return false;
    }
    return true;
}

void printBox(vector<Box>& boxes)
{
    for(int i=0;i<boxes.size();i++)
    {
        cout<<boxes[i].num<<": ";
        for(int j=0;j<boxes[i].sizes.size();j++)
        {
            cout<<boxes[i].sizes[j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    ifstream input("data.in");
    int dp[30];
    int K,N;
    while(input>>K>>N)
    {
        vector<Box> boxes;
        for(int i=1;i<=K;i++)
        {
            Box tmp;
            tmp.num = i;
            for(int j=0;j<N;j++)
            {
                int s;
                input>>s;
                tmp.sizes.push_back(s);
            }
            sort(tmp.sizes.begin(),tmp.sizes.end());
            boxes.push_back(tmp);
        }

        sort(boxes.begin(),boxes.end(),comp);
//        printBox(boxes);
        //DP:
        int max_i = 0;
        int max_n = 1;
        for(int i=0;i<K;i++)
        {
            dp[i] = 0;
        }
        dp[0] = 1;
        for(int i=1;i<K;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nests(boxes[j],boxes[i]))
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if(dp[i]>max_n)
            {
                max_n = dp[i];
                max_i = i;
            }
        }

        cout<<max_n<<endl;
        vector<int>result;
        result.push_back(boxes[max_i].num);
        int pre = max_i;
        for(int i=max_i-1;i>=0;i--)
        {
            if(nests(boxes[i],boxes[pre]) && dp[i] == max_n-result.size())
            {
                result.push_back(boxes[i].num);
                pre = i;
            }
        }
        for(int i=result.size()-1;i>=0;i--)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;

    }


    return 0;
}
