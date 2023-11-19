#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN=1e5+5;
const ll inf=2e18;
struct go
{
    ll w,d;
};
go a[maxN+1],sum[maxN+1];
ll res=inf;
ll n,sumwd[maxN+1],ans[maxN+1],s;
ll get(ll l,ll r)
{
    return s-sum[l].w*(sum[r].d-sum[l].d)-sum[r].w*(sum[n+1].d-sum[r].d);
}
void solve(ll l,ll r,ll u,ll v)
{
    if(l>=u)
    {
        u=l+1;
    }
    if(r>=v)
    {
        r=v-1;
    }
    if(l>r||u>v)
    {
        return;
    }
    ll mid=(u+v)/2;
    ll ans=inf,pos=0;
    for(int i=l;i<=min(r,mid-1);i++)
    {
        ll cur=get(i,mid);
        if(cur<ans)
        {
            ans=cur;
            pos=i;
        }
    }
    if(ans<res)
    {
        res=ans;
    }
    solve(l,pos,u,mid-1);
    solve(pos,r,mid+1,v);
}
int main()
{
    freopen("SAWMILL.INP","r",stdin);
    freopen("SAWMILL.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].w>>a[i].d;
    }
    s=a[1].w*a[1].d;
    sum[1].d=0;
    sum[2].d=a[1].d;
    sum[1].w=a[1].w;
    for(int i=2;i<=n;i++)
    {
        sum[i].w=sum[i-1].w+a[i].w;
        sum[i+1].d=sum[i].d+a[i].d;
        s+=sum[i].w*a[i].d;
    }
    solve(1,n,0,n+1);
    cout<<res;
}
/*9
1 2
2 1
3 3
1 1
3 2
1 6
2 1
1 2
1 1*/
