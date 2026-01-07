#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int discs, int A, int C, int B){
    if(discs==1){
        cout<<A<<" "<<C<<endl;
        return;
    }
    towerOfHanoi(discs-1,A,B,C);
    cout<<A<<" "<<C<<endl;
    towerOfHanoi(discs-1,B,C,A);
}
int main(){
 int n;
 cin>>n;
 cout<<(1<<n)-1<<endl;
 towerOfHanoi(n,1,3,2);
return 0;
}