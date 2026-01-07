#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int n = s.size();
    map<char,int>mp;
    for(auto it:s){
        mp[it]++;
    }
    int odd = 0;
    char mid;
    for(auto it:mp){
        if(it.second&1){
            odd++;
            mid = it.first;
        }
        if(odd>1){
            cout<<"NO SOLUTION"<<endl;
            return;
        }
    }
    string ans = "";
    for(auto it:mp){
        for(int i = 0;i<it.second/2;i++){
            ans+=it.first;
        }
    }
    string rev = ans;
    reverse(rev.begin(),rev.end());
    if(odd){
        ans+=mid;
    }
    ans+=rev;
    cout<<ans<<endl;
}
int main(){
    solve();
return 0;
}