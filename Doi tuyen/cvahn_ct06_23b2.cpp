#include<bits/stdc++.h>
using namespace std;
const int N=8640000;
int n;
int p1,q1,rr1,s1;
int a[N+5],c[N+5];
int mx1,l1,r1,len1,mx2,l2,r2,len2;
int resl1,resl2,resr1,resr2;
int main() {
    freopen("CTMT.INP","r",stdin);
    freopen("CTMT.OUT","w",stdout);
    cin>>n;
    while (n--) {
        int u,v;
        cin>>u>>v;
        c[u]++;
        c[v+1]--;
    }
    cin>>p1>>q1>>rr1>>s1;
    a[0]=c[0];
    for (int i=1;i<=N;i++) a[i]=a[i-1]+c[i];
    bool f1=false,f2=false;
    for (int i=p1;i<=q1;i++) if (a[i]==0) f1=true;
    for (int i=rr1;i<=s1;i++) if (a[i]!=0) f2=true;
    if (f1) cout<<0<<'\n';
    else cout<<1<<'\n';
    if (f2) cout<<0<<'\n';
    else cout<<1<<'\n';
    if (a[0]==0) len2=1;
    else len1=1;
    if (len1>mx1) {
        resl1=l1;
        resr1=r1;
        mx1=len1;
    }
    if (len2>mx2) {
        resl2=l2;
        resr2=r2;
        mx2=len2;
    }
    for (int i=1;i<=N;i++) {
        if (a[i]==0&&a[i-1]==0) {
            len2++;
            r2=i;
        } else if (a[i]==0&&a[i-1]!=0) {
            len2=1;
            len1=0;
            l2=i;
            r2=i;
        } else if (a[i]!=0&&a[i-1]!=0) {
            len1++;
            r1=i;
        } else {
            len1=1;
            len2=0;
            l1=r1=i;
        }
        if (len1>mx1) {
            resl1=l1;
            resr1=r1;
            mx1=len1;
        }
        if (len2>mx2) {
            resl2=l2;
            resr2=r2;
            mx2=len2;
        }
    }
    cout<<resl1<<' '<<resr1<<'\n'<<resl2<<' '<<resr2;
}
/*
5
1000 10000
2000 30000
20000 100000
200000 500000
8000000 8500000
1000 100000
0 1000
*/
