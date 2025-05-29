#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector<long long>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];
long long maxi = arr[0];
long long ans = 0;
for(int i = 1;i<n;i++){
    if(arr[i]<maxi){
        ans+=maxi-arr[i];
    }
    maxi=max(maxi,arr[i]);
}
cout<<ans<<endl;
return 0;
}