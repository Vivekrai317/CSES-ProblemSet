#include <bits/stdc++.h>
using namespace std;
bool bfs(int i, vector<int>&visited,vector<vector<int>>&adj){
    queue<int>q;
    visited[i]=1;
    q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(visited[it]==-1){
                q.push(it);
                visited[it]=3-visited[node];
            }else if(visited[it]==visited[node]){
                return false;
            }
        }
    }
    return true;
}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>adj(n+1);
vector<int>visited(n+1,-1);
for(int i = 0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
for(int i = 1;i<=n;i++){
    if(visited[i]==-1){
        if(bfs(i,visited,adj)==false){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
}
for(int i = 1;i<=n;i++){
    cout<<visited[i]<<" ";
}

return 0;
}