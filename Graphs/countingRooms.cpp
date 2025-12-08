#include <bits/stdc++.h>
using namespace std;

void bfs(int i , int j, vector<vector<char>>&grid, vector<vector<int>>&visited){
    int n = grid.size();
    int m = grid[0].size();
    visited[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    int delrow[4] = {0,1,0,-1};
    int delcol[4] = {1,0,-1,0};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int it = 0;it<4;it++){
            int nrow = row + delrow[it];
            int ncol = col + delcol[it];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='.'){
                visited[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i = 0;i<n;i++){
        for(int j= 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int ans = 0;
    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]=='.' && !visited[i][j]){
                ans++;
                bfs(i,j,grid,visited);
            }
        }
    }
     cout<<ans<<endl;
return 0;
}