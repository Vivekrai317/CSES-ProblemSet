#include <bits/stdc++.h>
using namespace std;
void solve(int index, string &s, set<string>&ans){
    ans.insert(s);
    for(int i = index;i<s.size();i++){
        swap(s[i],s[index]);
        solve(index+1,s,ans);
        swap(s[i],s[index]);
    }
}
int main(){
 string s;
 cin>>s;
 sort(s.begin(),s.end());
 set<string>ans;
 string temp;
 solve(0,s,ans);
 cout<<ans.size()<<endl;
 for(auto it:ans){
    cout<<it<<endl;
 }
return 0;
}