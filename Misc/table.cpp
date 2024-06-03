#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,k;
signed main(){
    cin>>n>>m>>k;
    int l=1,r=m*n,res=0;
    while(l<=r){
        int md=(l+r)/2,d=0;
        for (int i=1;i<=n;i++) d+=min(md/i,m);
        //cout<<md<<' '<<d<<endl;
        if(d>=k){
            res=md;
            r=md-1;
        }else l=md+1;
    }
    cout<<res;
}