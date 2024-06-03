#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,p,a[N+5],res;
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int l=i+1,r=n,ri=0;
        while(l<=r){
            int m=(l+r)/2;
            if(a[i]+a[m]<=p){
                ri=m;
                l=m+1;
            }else r=m-1;
        }
        res+=max(0,ri-i);
    }
    cout<<res;
}