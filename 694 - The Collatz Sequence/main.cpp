#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
    int A,L;
//    ifstream input("data.in");
    cin>>A>>L;
    int Case = 0;
    while(A>=0 && L>=0)
    {
        Case ++;
        unsigned int count = 1;
        unsigned long term = A;
        while(term<=L)
        {
            if(term == 1)
            {
                cout<<"Case "<<Case<<": A = "<<A<<", limit = "<<L<<", number of terms = "<<count<<endl;
                break;
            }
            if(term % 2 == 0)
            {
                term = term/2;
                count++;
            }
            else
            {
                term = 3*term + 1;
                if(term <= L)
                    count++;
            }
        }
        if(term > L)
        {
            cout<<"Case "<<Case<<": A = "<<A<<", limit = "<<L<<", number of terms = "<<count<<endl;
        }
        cin>>A>>L;
    }
    return 0;
}
