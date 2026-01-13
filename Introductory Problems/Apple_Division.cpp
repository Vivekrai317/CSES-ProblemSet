#include <bits/stdc++.h>
using namespace std;
void solve(int index, long long g1, long long g2, long long &ans, vector<long long>&arr){
    if(index == arr.size()){
        ans = min(ans,abs(g1-g2));
        return;
    }
    solve(index+1,g1+arr[index],g2,ans,arr);
    solve(index+1,g1,g2+arr[index],ans,arr);
}
int main(){
 int n;
 cin>>n;
 vector<long long>arr(n);
 for(int i = 0;i<n;i++)cin>>arr[i];
 long long ans = INT_MAX;
 solve(0,0,0,ans,arr);
 cout<<ans<<endl;
return 0;
}