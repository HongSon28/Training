#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int par[N+5],res;
int findroot(int u) {
    if (par[u]<0) return u;
    return par[u]=findroot(par[u]);
}
void Union(int u,int v) {
    if ((u=findroot(u))==(v=findroot(v))) return;
    if (par[v]<par[u]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
struct point{
    long long x,y;
};
struct rect{
    point a,b,c,d;
}a[N+5];
bool ccw(point a,point b,point c) {
    return (c.y-a.y)*(b.x-a.x)>(b.y-a.y)*(c.x-a.x);
}
bool chk(point a,point b,point c) {
    return ((c.y-a.y)*(b.x-a.x)==(b.y-a.y)*(c.x-a.x)&&a.x<=b.x&&b.x<=c.x&&a.y<=b.y&&b.y<=c.y);
}
bool intersect(point a,point b,point c,point d) {
    return (((ccw(a,c,d)!=ccw(b,c,d))&&(ccw(a,b,c)!=ccw(a,b,d)))||(chk(a,c,b))||(chk(b,c,a))||(chk(a,d,b))||(chk(b,d,a))||(chk(c,a,d))||(chk(d,a,c))||(chk(c,b,d))||(chk(d,b,c)));
}
bool in(rect a,point b) {
    return (ccw(a.a,a.b,b)==ccw(a.b,a.c,b)&&ccw(a.b,a.c,b)==ccw(a.c,a.d,b)&&ccw(a.c,a.d,b)==ccw(a.d,a.a,b));
}
bool val(rect x,rect y) {
    return (intersect(x.a,x.b,y.a,y.b)||intersect(x.a,x.b,y.b,y.c)||intersect(x.a,x.b,y.c,y.d)||intersect(x.a,x.b,y.d,y.a)||
            intersect(x.b,x.c,y.a,y.b)||intersect(x.b,x.c,y.b,y.c)||intersect(x.b,x.c,y.c,y.d)||intersect(x.b,x.c,y.d,y.a)||
            intersect(x.c,x.d,y.a,y.b)||intersect(x.c,x.d,y.b,y.c)||intersect(x.c,x.d,y.c,y.d)||intersect(x.c,x.d,y.d,y.a)||
            intersect(x.a,x.d,y.a,y.b)||intersect(x.a,x.d,y.b,y.c)||intersect(x.a,x.d,y.c,y.d)||intersect(x.a,x.d,y.d,y.a)||
            in(x,y.a)||in(x,y.b)||in(x,y.c)||in(x,y.d)||in(y,x.a)||in(y,x.b)||in(y,x.c)||in(y,x.d));
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].a.x>>a[i].a.y>>a[i].b.x>>a[i].b.y>>a[i].c.x>>a[i].c.y>>a[i].d.x>>a[i].d.y;
    memset(par,-1,sizeof(par));
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            //cout<<i<<' '<<j<<' '<<val(a[i],a[j])<<endl;
            if (val(a[i],a[j])) Union(i,j);
        }
    }
    for (int i=1;i<=n;i++)
        if (par[i]<0) res=max(res,-par[i]);
    cout<<res;
}
