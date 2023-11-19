#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,mx;
int a[N+5];
int calc(int x,int y) {
    cout<<x<<' '<<y<<endl;
    return min(abs(a[x]-a[y]),m-(abs(a[x]-a[y])));
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[n+i]=a[i]+m;
    }
    sort(a+1,a+1+2*n);
    for (int i=1;i<=n;i++) {
        if (a[i]+m/2<=m) res=min(res,sum[i+n-1]-sum[i-1]-)
    }
}
