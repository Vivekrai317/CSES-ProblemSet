#include <bits/stdc++.h>
using namespace std;

int main(){
long long n;
cin>>n;
long long mod = 1e9+7;
long long res = 1;
long long a = 2;
while(n>0){
    if(n&1)
        res = (res*a)%mod;
    a = a*a%mod;
    n/=2;
}
cout<<res<<endl;
return 0;
}