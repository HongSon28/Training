#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
const int maxN=1e5+5;
ll n,q,w[maxN+1],ans[maxN+1];
pll t[maxN+1];
deque<ll> neg,pos;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    sort(w+1,w+n+1);
    for(int i=1;i<=q;i++)
    {
        cin>>t[i].fi;
        t[i].se=i;
    }
    sort(t+1,t+q+1);
    ll sumn=0,sump=0,cur=t[1].fi;
    for(int i=1;i<=n;i++)
    {
        if(w[i]+cur<0)
        {
            neg.push_back(w[i]);
            sumn+=w[i];
        }
        else
        {
            pos.push_back(w[i]);
            sump+=w[i];
        }
    }
    for(int i=1; i<=q;i++)
    {
        ll k=t[i].first,res;
        while(!neg.empty()&&neg.back()+k>=0)
        {
            pos.push_front(neg.back());
            sump+=neg.back();
            sumn-=neg.back();
            neg.pop_back();
        }
        if(!neg.empty()&&pos.empty())
        {
            ll tmp=neg.back(),len=neg.size();
            res=(sumn+len*k)*(tmp+k)-(tmp+k)*(tmp+k);
        }
        else if(!pos.empty()&&neg.empty())
        {
            ll tmp=pos.front(),len=pos.size();
            res=(sump+len*k)*(tmp+k)-(tmp+k)*(tmp+k);
        }
        else
        {
            ll tmp1=neg.front(),tmp2=pos.back(),len1= neg.size(),len2=pos.size();
            res=(sump+len2*k)*(tmp1+k)+(sumn+len1*k)*(tmp2+k)-(tmp1+k)*(tmp2+k);
        }
        ans[t[i].se]=res-(n-1)*k*k;
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<" ";
}
