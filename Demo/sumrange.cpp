#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    int psa[n+1]={},psb[n+1]={};
    int sum[n+1][n+1];
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        psa[i]=psa[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        psb[i]=psb[i-1]+b[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i<=j) {
                sum[i][j]=psa[j]-psa[i-1];
            } else {
                sum[i][j]=psb[i]-psb[j-1];
            }
        }
    }
}
