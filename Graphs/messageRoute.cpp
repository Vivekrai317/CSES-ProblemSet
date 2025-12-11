#include <bits/stdc++.h>
using namespace std;

int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>adj(n+1);
vector<int>parent(n+1,-1);
vector<int>visited(n+1,0);
for(int i = 0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

queue<int>q;
q.push(1);
visited[1]=1;
bool found = false;
while(!q.empty() &&  !found){
    int node = q.front();
    q.pop();
    for(auto it : adj[node]){
        if(!visited[it]){
            visited[it]=1;
            q.push(it);
            parent[it]=node;
        }
        if(it == n){
            found = true;
            break;
        }
    }
}

if(!found){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
vector<int>ans;
int curr = n;
while(curr!=-1){
    ans.push_back(curr);
    curr = parent[curr];
}

reverse(ans.begin(),ans.end());
cout<<ans.size()<<endl;
for(int i = 0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}


return 0;
}