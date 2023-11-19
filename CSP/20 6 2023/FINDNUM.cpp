#include<bits/stdc++.h>
using namespace std;
struct data {
    int i,j,gt;
    bool operator < (const data &b) const {
        return gt>b.gt;
    }
};
int main() {
    //freopen("FINDNUM.INP","r",stdin);
    //freopen("FINDNUM.OUT","w",stdout);
    int m,n,k;
    cin>>m>>n>>k;
    int a[m+1];
    int b[n+1];
    for (int i=1;i<=m;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+m);
    sort(b+1,b+1+n);
    priority_queue<data>q;
    for (int i=1;i<=n;i++) {
        q.push({1,i,a[1]+b[i]});
    }
    for (int i=1;i<=k;i++) {
        data t=q.top();
        q.pop();
        cout<<t.gt<<endl;
        if (t.i<m) {
            q.push({t.i+1,t.j,a[t.i+1]+b[t.j]});
        }
    }
}

