#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<long long,long long>p[N+5];
long long dp[N+5],res,inf=1e18;
bool comp(pair<long long,long long>x,pair<long long,long long>y) {
    if (x.second!=y.second) return x.second<y.second;
    return x.first<y.first;
}
int bs(int m) {
    int l=1,r=m-1,res=0;
    while (l<=r) {
        int mid=(l+r)/2;
        if (p[mid].second<=p[m].first) {
            res=mid;
            l=mid+1;
        } else r=mid-1;
    }
    return res;
}
long long st[N*4+5];
void update(int id,int l,int r,int pos,long long val) {
    if (l>pos||r<pos) return;
    if (l==r) {
        st[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=max(st[id*2],st[id*2+1]);
}
long long get(int id,int l,int r,int u,int v) {
    if (v<l||r<u||u>v) return -inf;
    if (u<=l&&r<=v) {
        return st[id];
    }
    int mid=(l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p[i].first>>p[i].second;
    }
    for (int i=1;i<=N*4;i++) st[i]=-inf;
    sort(p+1,p+1+n,comp);
    for (int i=1;i<=n;i++) {
        int j=bs(i);
        dp[i]=max(dp[i-1],dp[j]+p[i].second-p[i].first);
        dp[i]=max(dp[i],get(1,1,n,j+1,i-1)+p[i].first+p[i].second);
        res=max(res,dp[i]);
        update(1,1,n,i,dp[i]-2*p[i].second);
    }
    cout<<res;
}
/*
7
100 150
0 1000
900 1000
1800 2000
900 1800
272 314
1900 2000
*/
