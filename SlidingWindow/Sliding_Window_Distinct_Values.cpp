#include <bits/stdc++.h>
using namespace std;
int main(){

    int n,k;
    cin>>n>>k;
    vector<long long>arr(n);
    for(int i = 0;i<n;i++)cin>>arr[i];

    map<int,int>mp;//int->freq
    int i = 0, j = 0;
    int ans = 0,wdis = 0;
    while(j<n){
        mp[arr[j]]++;
        if((j-i+1)>=k){
            cout<<mp.size()<<" ";
            mp[arr[i]]--;
            if(mp[arr[i]]==0)mp.erase(arr[i]);
            i++;
        }
        j++;
    }
return 0;
}