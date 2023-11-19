#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int MX=__lg(N);
int res;
int n,p;
int a[N+5];
int rm1[N+5][MX+1],rm2[N+5][MX+1];
int cal(int l,int r) {
    int len=r-l+1;
    int k=__lg(len);
    return max(rm2[l][k],rm2[r-(1<<k)+1][k])-min(rm1[l][k],rm1[r-(1<<k)+1][k]);
}
bool check(int m) {
    for (int r=m;r<=n;r++) {
        int l=r-m+1;
        if (cal(l,r)<=p) return true;
    }
    return false;
}
int main() {
    cin>>n>>p;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        rm1[i][0]=a[i];
        rm2[i][0]=a[i];
    }
    for (int j=1;j<=MX;j++) {
        for (int i=1;i<=n-(1<<j)+1;i++) {
            rm1[i][j]=min(rm1[i][j-1],rm1[i+(1<<(j-1))][j-1]);
            rm2[i][j]=max(rm2[i][j-1],rm2[i+(1<<(j-1))][j-1]);
        }
    }
    int lo=1,hi=n;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)){
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout<<res;
}
