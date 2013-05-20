#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

typedef struct
{
    int left;
    int height;
    int right;
} Building;

int compH(Building b1,Building b2)
{
    return b1.height<b2.height;
}

int main()
{
    ifstream input("data.in");
    vector<Building> buildings;
    int l,h,r;
    int minl = 10000;
    int maxr = 0;
    while(input>>l>>h>>r)
    {
        Building tmp;
        tmp.left = l;
        tmp.height = h;
        tmp.right = r;
        buildings.push_back(tmp);
        if(l<minl)
            minl = l;
        if(r>maxr)
            maxr = r;
    }
//    sort(buildings.begin(),buildings.end(),compH);
    int *land = new int[maxr-minl];
    memset(land,0,(maxr-minl)*sizeof(int));
    for(int i=buildings.size()-1; i>=0; i--)
    {
        Building tmp = buildings[i];
        for(int j=tmp.left-minl;j<tmp.right-minl;j++)
        {
            if(tmp.height>land[j])
                land[j] = tmp.height;
        }
    }

    cout<<minl<<" ";
    cout<<land[0]<<" ";
    int currH = land[0];
    for(int i=0;i<maxr-minl;i++)
    {
        if(currH == land[i]) continue;
        cout<<minl+i<<" ";
        cout<<land[i]<<" ";
        currH = land[i];
    }
    cout<<maxr<<" ";
    cout<<0<<endl;

    return 0;
}
