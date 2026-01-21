#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    long long x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<long long>arr(n);
    for(int i = 0;i<n;i++){
        if(i==0){
            arr[i]=x;
        }
        else{
            arr[i]=(arr[i-1]*a+b)%c;
        }
    }
    vector<long long>p(n,0),s(n,0);
    for(int i = 0;i<n;i++){
        if(i%k==0){
            p[i]=arr[i];
        }else{
            p[i] = min(p[i-1],arr[i]);
        }
    }
    s[n-1]=arr[n-1];
    for(int i = n-2;i>=0;i--){
        if(i%k==k-1){
            s[i]=arr[i];
        }else{
            s[i]=min(arr[i],s[i+1]);
        }
    }

    int ans = 0;
    for(int i = k-1;i<n;i++){
        ans ^= min(p[i],s[i-k+1]);
    }
    cout<<ans<<endl;
return 0;
}