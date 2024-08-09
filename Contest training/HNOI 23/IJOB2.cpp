#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN=2e5+5;
ll n,p[maxN+1],w[maxN+1],t[maxN+1],deg[maxN+1];
vector<ll> adj[maxN+1],topo;
queue<ll> q;
bool comp(ll a,ll b) {
    double x=(double)w[a]/(double)t[a];
    double y=(double)w[b]/(double)t[b];
    return x>y;
}
ll res,cur;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        if(i==0)
        {
            continue;
        }
        deg[i]++;
        adj[p[i]].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
    }
    for(int i=0;i<n;i++)
    {
        if(!deg[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ll tmp=q.front();
        q.pop();
        topo.push_back(tmp);
        sort(adj[tmp].begin(),adj[tmp].end(),comp);
        for(auto v:adj[tmp])
        {
            deg[v]--;
            if(!deg[v])
            {
                q.push(v);
            }
        }
    }
    for(auto i:topo)
    {
        cur+=t[i];
        res+=cur*w[i];
    }
    cout<<res;
}
