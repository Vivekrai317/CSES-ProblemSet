#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long>arr(n);
    for(int i = 0;i<n;i++)cin>>arr[i];
    map<int,int>freq;
    map<int,set<int>>inverse;
    int i=0,j=0;
    while(j<n){
        int oldFreq = freq[arr[j]]++;
        //addition 
        if(oldFreq>=1){
            inverse[oldFreq].erase(arr[j]);
        }
        if((inverse[oldFreq].size())==0){
            inverse.erase(oldFreq);
        }
        inverse[oldFreq+1].insert(arr[j]);
        if(j-i+1>=k){                                  
           auto& element = *rbegin(inverse);
            cout<<*begin(element.second)<<" ";

        //removal
        int fr = freq[arr[i]]--;
        if(freq[arr[i]]==0){
            freq.erase(arr[i]);
        }
        inverse[fr].erase(arr[i]);
        if(inverse[fr].size()==0){
            inverse.erase(fr);
        }
        if(fr>1){
            inverse[fr-1].insert(arr[i]);
        }
            i++;
        }
        j++;
    }
return 0;
}