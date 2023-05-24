#include<bits/stdc++.h>
using namespace std;
int main() {
    //freopen("PAIR.INP","r",stdin);
    //freopen("PAIR.OUT","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int b[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);

    for (int i=1;i<=k;i++) {
        data t=q.top();
        q.pop();
        if (i==k)
            cout<<t.gt<<endl;
        if (t.i<n) {
            q.push({t.i+1,t.j,a[t.i+1]+b[t.j]});
        }
    }
}

