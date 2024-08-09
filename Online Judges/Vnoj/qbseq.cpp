#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k,res=0;
    cin>>n>>k;
    int a[n+1],sum[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    sum[0]=0;
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            int t=sum[j]-sum[i-1];
            if (t%k==0) {
                res=max(res,j-i+1);
            }
        }
    }
    cout<<res;
}
