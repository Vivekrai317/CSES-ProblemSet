#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sum = n*1LL*(n+1)/2;
    if(sum%2){
        cout<<"NO"<<endl;
    }else{
        sum = sum/2;
        vector<int>v1,v2;
        for(int i = n;i>=1;i--){
            if(i<=sum){
                v1.push_back(i);
                sum-=i;
            }else{
                v2.push_back(i);
            }
        }
        cout<<"YES"<<endl;
        cout<<v1.size()<<endl;
        for(int i = 0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
        cout<<v2.size()<<endl;
        for(int i = 0;i<v2.size();i++){
            cout<<v2[i]<<" ";
        }
        cout<<endl;
    }

    

return 0;
}