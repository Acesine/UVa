#include <iostream>
#include <fstream>

using namespace std;

int board[8][8];
void clearBoard()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            board[i][j] = 0;
        }
    }
}

bool Solver(int col)
{
    if(col == 7)
}

int main()
{
    ifstream input("data.in");
    int pos[8];
    while(input>>pos[0]>>pos[1]>>pos[2]>>pos[3]>>pos[4]>>pos[5]>>pos[6]>>pos[7])
    {
        clearBoard();

    }
    return 0;
}
