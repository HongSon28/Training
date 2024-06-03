#include<bits/stdc++.h>
#define int long long
using namespace std;
int k;
signed main(){
    cin>>k;
    int l=3,r=1e9,res=0;
    while(l<=r){
        int m=(l+r)/2;
        int f3=m/3,f5=m/5,f7=m/7,f35=m/15,f57=m/35,f37=m/21,f357=m/105;
        int n=f3+f5+f7-f35-f37-f57+f357;
        if(n==k) {
        	res=m;
        	r=m-1;
        }
        else if(n<k) l=m+1;
        else r=m-1;
    }
    cout<<res;
}