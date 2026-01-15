#include <bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<vector<char>>grid(n,vector<char>(m));
for(int i = 0;i<n;i++){
    for(int j = 0 ;j<m;j++){
        cin>>grid[i][j];
    }
}
vector<char>valid = {'A','B','C','D'};
for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        set<char>st;
        if(i>0)st.insert(grid[i-1][j]);
        if(j>0)st.insert(grid[i][j-1]);
        st.insert(grid[i][j]);
        for(auto it:valid){
            if(st.find(it)==st.end()){
                grid[i][j]=it;
            }
        }
    }
}
for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        cout<<grid[i][j];
    }
    cout<<endl;
}
return 0;
}