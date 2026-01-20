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
        }else{
            arr[i] = (a*arr[i-1]+b)%c;
        }
    }
    long long wsum=0,ans=0;
    int j = 0,i = 0;
    while(j<n){
        wsum+=arr[j];
        if((j-i+1)>=k){
            ans^=wsum;
            wsum-=arr[i];
            i++;
        }
        j++;
    }
    cout<<ans<<endl;
    return 0;
}