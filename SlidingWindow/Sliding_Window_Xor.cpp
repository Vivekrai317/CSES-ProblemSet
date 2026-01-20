#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    long long x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<long long>arr(n);
    for(int i = 0;i<n;i++){
        if(i==0)arr[i]=x;
        else{
            arr[i]=(arr[i-1]*a+b)%c;
        }
    }
    int i = 0,j=0;
    int wxor=0,ans=0;
    while(j<n){
        wxor^=arr[j];
        if((j-i+1)>=k){
            ans^=wxor;
            wxor^=arr[i];
            i++;
        }
        j++;
    }
    cout<<ans<<endl;
return 0;
}