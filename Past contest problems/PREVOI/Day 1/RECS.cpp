#include<bits/stdc++.h>
using namespace std;
int t;
long long a[3],b[3],x[3],y[3];
long long calc() {
    long long res=LLONG_MAX;
    long long temp=x[0]+x[1];
    if (y[0]<y[1]) {
        swap(y[0],y[1]);
        swap(x[0],x[1]);
    }
    res=min(res,(temp+x[2])*max({y[0],y[1],y[2]}));
    res=min(res,(x[0]+max(x[1],x[2]))*max(y[0],y[1]+y[2]));
    res=min(res,(y[0]+y[2])*max(temp,x[2]));
    if (x[0]<x[1]) {
        swap(x[0],x[1]);
        swap(y[0],y[1]);
    }
    temp=y[0]+y[1];
    res=min(res,(x[0]+x[2])*(max(temp,y[2])));
    res=min(res,max(x[0],x[1]+x[2])*(y[0]+max(y[1],y[2])));
    res=min(res,max({x[0],x[1],x[2]})*(temp+y[2]));
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("RECS.INP","r",stdin);
    freopen("RECS.OUT","w",stdout);
    cin>>t;
    while (t--) {
        long long res=LLONG_MAX;
        cin>>a[0]>>b[0]>>a[1]>>b[1]>>a[2]>>b[2];
        for (int i=0;i<(1<<3);i++) {
            x[0]=a[0];
            x[1]=a[1];
            x[2]=a[2];
            y[0]=b[0];
            y[1]=b[1];
            y[2]=b[2];
            if (i>>0&1) swap(x[0],y[0]);
            if (i>>1&1) swap(x[1],y[1]);
            if (i>>2&1) swap(x[2],y[2]);
            res=min(res,calc());
        }
        cout<<res<<'\n';
    }
}
