#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("DARR.INP","r",stdin);
    freopen("DARR.OUT","w",stdout);
    long long res=0;
    int n,k;
    cin>>n>>k;
    long long a[n+5];
    long long sum[n+5]={};
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int start=1;
    int cnt=k;
    for (int i=1;i<=k;i++) {
        long long mn=1e18;
        int pos;
        for (int i=start;i<=n-cnt+1;i++) {
            if (sum[i]<mn) {
                mn=sum[i];
                pos=i;
            }
        }
        res+=(sum[pos]-sum[start-1])*i;
        //cout<<start<<' '<<pos<<' '<<res<<endl;
        cnt--;
        start=pos+1;
    }
    if (start<=n) res+=(sum[n]-sum[start-1])*k;
    cout<<res;
}
