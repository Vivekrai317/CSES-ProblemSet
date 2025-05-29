#include <bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
int ans = 1;
int count = 1;
for(int i=1;i<s.size();i++){
    if(s[i]==s[i-1])count++;
    else count = 1;
    ans = max(ans,count);
}
cout<<ans<<endl;
return 0;
}