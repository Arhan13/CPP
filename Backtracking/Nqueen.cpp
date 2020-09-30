//Template
#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = int(a); i < int(n); i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll;
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    //You check the column
    for (int row = 0; row <=i; row++)
    {
        if (board[row][j] == 1)
        {
            return false;
        }
    }
    //You can check for left diagonal
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool solveNQueen(int board[][10], int i, int n)
{
    //Base Case
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    cout << "Q";
                }
                else
                {
                    cout << "_";
                }
            }
            cout << endl;
        }
        return false;
    }
    //Recursive Case
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n)){
            board[i][j] = 1;
            bool canWePlaceNextQueen = solveNQueen(board, i+1, n);
            if(canWePlaceNextQueen==1){
                return true;
            }
            //If we come here we know our clame was wrong
            else{
                board[i][j] = 0;
            }
            
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int board[10][10] = {0};
    int n;cin>>n;
    solveNQueen(board, 0, n);
    return 0;
}