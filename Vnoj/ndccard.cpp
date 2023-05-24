#include<bits/stdc++.h>
using namespace std;
int a[10005];
int n,m;
int res;
pair<int,int> f[200005];
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
        for (int j=i+1;j<=n;j++) {
            f[a[i]+a[j]]={i,j};
        }
    }
    m=min(m,30000);
    for (int i=1;i<=n;i++) {
        for (int j=m-a[i];j>=0;j--) {
            if (f[j]!=pair<int,int>(0,0)&&f[j].first!=i&&f[j].second!=i) {
                res=max(res,j+a[i]);
                break;
            }
        }
    }
    cout<<res;
}
