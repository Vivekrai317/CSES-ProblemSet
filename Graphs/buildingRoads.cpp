#include <bits/stdc++.h>
using namespace std;
void bfs(int i, vector<int>&visited, vector<vector<int>>&adj){
    visited[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int node = q. front();
        q.pop();
        for(auto it : adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>visited(n+1,0);
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>representatives;
    for(int i = 1;i<=n;i++){
        if(!visited[i]){
            representatives.push_back(i);
            bfs(i,visited,adj);
        }
    }
    cout<<representatives.size()-1<<endl;
    for(int i = 1;i<representatives.size();i++){
        cout<<representatives[0]<<" "<<representatives[i]<<endl;
    }

return 0;
}