#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n,a[N+5];
set<int>s;
int res[N+5],inf=1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        for (int j=1;j*j<=a[i];j++) {
            s.insert(j);
            s.insert(a[i]/(j+1)+1);
        }
        res[i]=inf;
        s.insert(a[i]+1);
    }
    a[n+1]=inf;
    sort(a+1,a+2+n);
    for (auto x:s) {
        int cnt=1;
        for (int i=2;i<=n+1;i++) {
            if (a[i]/x==a[i-1]/x) cnt++;
            else {
                res[cnt]=min(res[cnt],x);
                cnt=1;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (res[i]==inf) cout<<-1<<'\n';
        else cout<<res[i]<<'\n';
    }
}
