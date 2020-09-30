//Template
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll; 
using namespace std;

bool ratInTheMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n){
    if(i==m && j==n){
        soln[m][n] = 1;
        //Print Path
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //Rat should be inside the grid
    if(i>m || j>n){
        return false;
    }
    if(maze[i][j]=='X'){
        return false;
    }
    //Assuming the solution exists
    soln[i][j] = 1;

    //If the solution exists in the left or right then only soliditify
    bool rightSucess = ratInTheMaze(maze, soln, i, j+1, m, n);
    bool downSucess = ratInTheMaze(maze, soln, i+1, j, m, n);

    //Backtracking 
    //We will mark the cell 0 irrespective of the solidification
    soln[i][j] = 0;

    if(rightSucess||downSucess){
        return true;
    }
    else{
        return false;
    }
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    char maze[10][10] = {
            "0000",
            "00X0",
            "000X",
            "0X00",
        };
    int soln[10][10] = {0};
    int m = 4;
    int n = 4;
    bool ans = ratInTheMaze(maze, soln, 0, 0, m-1, n-1);
    if(ans==0){
        cout<<"Path dosent exist ;)";
    }
    return 0;

}