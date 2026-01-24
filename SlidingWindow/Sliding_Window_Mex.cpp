#include <bits/stdc++.h>
using namespace std;
int main(){
 int n,k;
 cin>>n>>k;
 vector<int>arr(n);
 for(int i = 0;i<n;i++)cin>>arr[i];
 set<int>unseen;
 map<int,int>seen;
 for(int i = 0;i<=k;i++)unseen.insert(i);
 int i = 0,j=0;
 while(j<n){
    seen[arr[j]]++;
    if(unseen.find(arr[j])!=unseen.end()){
        unseen.erase(arr[j]);
    }
    if(j-i+1>=k){
        cout<<*begin(unseen)<<" ";
        seen[arr[i]]--;
        if(seen[arr[i]]==0){
            seen.erase(arr[i]);
            unseen.insert(arr[i]);
        }
        i++;
    }
    j++;
 }
return 0;
}