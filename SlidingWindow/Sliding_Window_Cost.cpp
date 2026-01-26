#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
 int n,k;
 cin>>n>>k;
 vector<int>arr(n);
 for(int i = 0;i<n;i++)cin>>arr[i];
 multiset<ll>left;
 multiset<ll>right;
 ll leftSum=0,rightSum=0;

 auto rebalance = [&]{
    if(left.size()>right.size()){
        long long v = *rbegin(left);
        leftSum-=v;
        rightSum+=v;

        left.erase(left.find(v));
        right.insert(v);
    }
    if(right.size()>left.size()+1){
        ll v = *begin(right);
        rightSum-=v;
        leftSum+=v;
        right.erase(right.find(v));
        left.insert(v);
    }
 };
 auto add = [&](ll element){
    ll median = *begin(right);
    if(!right.empty() && element>=median){
        rightSum+=element;
        right.insert(element);
    }else{
        leftSum+=element;
        left.insert(element);
    }
    rebalance();
 };

 auto remove = [&](ll element){
    ll median = *begin(right);
    if(element>=median){
        rightSum-=element;
        right.erase(right.find(element));
    }else{
        leftSum-=element;
        left.erase(left.find(element));
    }
    rebalance();
 };

 auto cost = [&]{
    ll median = *begin(right);
    return left.size()*median - leftSum + rightSum - right.size()*median;
 };

 int i = 0,j=0;
 while(j<n){
    add(arr[j]);

    if(j-i+1>=k){
        cout<<cost()<<" ";
        remove(arr[i]);
        i++;
    }
    j++;
 }
return 0;
}