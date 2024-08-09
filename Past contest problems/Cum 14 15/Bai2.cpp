#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n+1],sum[n+1]={};
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int res=0;
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            if (sum[j]-sum[i-1]==0) res=max(res,j-i+1);
        }
    }
    if (res==0) cout<<"NO SOLUTION";
    else cout<<res;
}
