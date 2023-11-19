#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long s1[N+5],s2[N+5],c[N+5];
int n,m,q;
long long a[N+5];
long long l[N+5],r[N+5],v[N+5];
int main() {
    freopen("UPDATE2.INP","r",stdin);
    freopen("UPDATE2.OUT","w",stdout);
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        s1[i]=a[i]-a[i-1];
    }
    for (int i=1;i<=m;i++) {
        cin>>l[i]>>r[i]>>v[i];
    }
    for (int i=1;i<=q;i++) {
        int x,y;
        cin>>x>>y;
        s2[x]++;
        s2[y+1]--;
    }
    for (int i=1;i<=m;i++) {
        c[i]=c[i-1]+s2[i];
        s1[l[i]]+=c[i]*v[i];
        s1[r[i]+1]-=c[i]*v[i];
        //cout<<l[i]<<' '<<r[i]<<' '<<v[i]<<' '<<c[i]<<endl;
    }
    for (int i=1;i<=n;i++) {
        a[i]=a[i-1]+s1[i];
        cout<<a[i]<<' ';
    }
}
