#include <bits/stdc++.h>
using namespace std;

void solve(){
        long long a,b;
        cin>>a>>b;
        if((2*a-b)%3==0){
            long long y = (2*a -b)/3;
            if(y>=0 && (b-y)%2==0){
                long long x = (b-y)/2;
                if(x>=0){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
        cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
return 0;
}