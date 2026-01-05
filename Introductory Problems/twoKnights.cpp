#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
for(int i = 1;i<=n;i++){
    long long totalCells = i*i;
    if(i==1){
        cout<<0<<endl;
    }else{
        long long total = ((totalCells)*(totalCells-1))/2;
        long long attacks = 2*2*(i-1)*(i-2);
        cout<<total - attacks<<endl;
    }
}
return 0;
}