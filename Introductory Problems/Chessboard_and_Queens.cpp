#include <bits/stdc++.h>
using namespace std;
bool is_safe(int row,int col, vector<string>&board){
    if(board[row][col]=='*')return false;
    //check prev cols
    int i = col-1;
    while(i>=0){
        if(board[row][i]=='Q')return false;
        i--;
    }
    i = row-1;
    int j = col-1;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q')return false;
        i--;
        j--;
    }
    i = row+1,j=col-1;
    while(i<8 && j>=0){
        if(board[i][j]=='Q')return false;
        i++;
        j--;
    }
    return true;
}
void solve(int col, int &count, vector<string>&board){
    if(col==8){
        count++;
        return;
    }
    for(int row = 0;row<8;row++){
        if(is_safe(row,col,board)){
            board[row][col] = 'Q';
            solve(col+1,count,board);
            board[row][col] = '.';
        }
    }
}
int main(){
 vector<string>board(8);
 for(int i = 0;i<8;i++)cin>>board[i];
 int count = 0;
 solve(0,count,board);
 cout<<count<<endl;
return 0;
}