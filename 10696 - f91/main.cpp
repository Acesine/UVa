#include <iostream>

using namespace std;

int f91(int N)
{
    if(N>=101)
    {
        return N-10;
    }
    else
    {
        return 91;
    }

}

int main()
{
    int N;
    cin>>N;
    while(N)
    {
        cout<<"f91("<<N<<") = "<<f91(N)<<endl;
        cin>>N;
    }
    return 0;
}
