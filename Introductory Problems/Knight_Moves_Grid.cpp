#include <bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin>>n;
 vector<vector<int>>grid(n,vector<int>(n));
 grid[0][0] = 0;
 queue<pair<pair<int,int>,int>>q;
 vector<vector<int>>visited(n,vector<int>(n,0));
 q.push({{0,0},0});
 visited[0][0]=1;
 int delrow[8] = {1,1,-1,-1,2,-2,2,-2};
 int delcol[8] = {2,-2,2,-2,1,1,-1,-1};
 while(!q.empty()){
    int row = q.front().first.first;
    int col = q.front().first.second;
    int moves = q.front().second;
    q.pop();
    for(int it = 0;it<8;it++){
        int nrow = row+delrow[it];
        int ncol = col+delcol[it];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !visited[nrow][ncol]){
            grid[nrow][ncol] = moves+1;
            visited[nrow][ncol] = 1;
            q.push({{nrow,ncol},moves+1});
        }
    }
 }
 for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        cout<<grid[i][j]<<" ";
    }
    cout<<endl;
 }
return 0;
}