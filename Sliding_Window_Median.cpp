#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
 int n,k;
 cin>>n>>k;
 vector<ll>arr(n);
 multiset<ll>left;
 multiset<ll>right;

 for(int i = 0;i<n;i++){
    cin>>arr[i];
 }

 auto rebalance = [&]{
    if(left.size()>right.size()){
        ll v = *rbegin(left);
        left.erase(left.find(v));
        right.insert(v);
    }

    if(right.size()>left.size()+1){
        ll v = *begin(right);
        right.erase(right.find(v));
        left.insert(v);
    }
 };

 auto add = [&](ll element){
    ll median = *begin(right);
    if(!right.empty() &&  element>=median){
        right.insert(element);
    }else{
        left.insert(element);
    }
    rebalance();
 };

 auto remove = [&](ll element){
    ll median = *begin(right);
    if(element>=median){
        right.erase(right.find(element));
    }else{
        left.erase(left.find(element));
    }
    rebalance();
 };

 int i = 0,j=0;
 while(j<n){
    add(arr[j]);
    if(j-i+1>=k){
        if(k%2!=0){
        cout<<*begin(right)<<" ";
        }else{
            cout<<*rbegin(left)<<" ";
        }
        remove(arr[i]);
        i++;
    }
    j++;
 }
return 0;
}