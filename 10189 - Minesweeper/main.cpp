#include <iostream>
#include <fstream>

using namespace std;

char board[100][100];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
    ifstream input("data.in");
    int n,m;
    input>>n>>m;
    int c = 1;
    while(n!=0 || m!=0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                input>>board[i][j];
                if(board[i][j]=='.')
                    board[i][j] = '0';
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == '*')
                {
                    for(int k=0;k<8;k++)
                    {
                        if(i+dx[k]>=0&&i+dx[k]<n&&j+dy[k]>=0&&j+dy[k]<m)
                        {
                            if(board[i+dx[k]][j+dy[k]]!='*')
                            {
                                board[i+dx[k]][j+dy[k]] += 1;
                            }
                        }
                    }
                }
            }
        }

        if(c>1)
            cout<<endl;
        cout<<"Field #"<<c<<":"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<board[i][j];
            }
            cout<<endl;
        }
        c++;
        input>>n>>m;
    }
    return 0;
}
