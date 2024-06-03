#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,s;
ll a[int(1e5)+4],ne[int(1e5)+4],sum[int(1e5)+4];
bool check(ll m, ll i){
    if(sum[m]-sum[i-1]>s) return true;
    return false;
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
         ll l=i,r=n,cnt=0;
         while(l<=r){
            ll m=(l+r)/2;
            if(check(m,i)){
                r=m-1;
                ne[i]=m;
            }
            else l=m+1;
        }
        if(ne[i]==0) ne[i]=n;
        //cout<<ne[i]<<' ';
        int j=ne[i]-1;
        while(j>0){
            if(j+1+j-i+1>n) {
                j--;
                continue;
            }
            if(check(j+1+j-i+1,j+1)) j--;
            else break;
        }
        cout<<j+1+j-i+1<<' ';
     //   if(j>=i) cout<<(j-i+1)*2<<'\n';
       // else cout<<0<<'\n';
    }
}
