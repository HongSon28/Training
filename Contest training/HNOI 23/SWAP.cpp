#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
int a[N+5];
int inf=1e9;
struct Segment{
    pair<int,int> st[N*4+5];
    pair<int,int> merge_node(pair<int,int>a,pair<int,int>b) {
        if (a.first==b.first)
            if (a.second<b.second) return a;
        if (a.first>b.first) return a;
        return b;
    }
    void build(int id,int l,int r) {
        if (l==r) {
            st[id].first=a[l];
            st[id].second=l;
            return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id]=merge_node(st[id*2],st[id*2+1]);
    }
    void update(int id,int l,int r,int pos) {
        if (l>pos||r<pos) return;
        if (l==r) {
            st[id].first=-inf;
            return;
        }
        int mid=(l+r)/2;
        update(id*2,l,mid,pos);
        update(id*2+1,mid+1,r,pos);
        st[id]=merge_node(st[id*2],st[id*2+1]);
    }
    pair<int,int>get(int id,int l,int r,int u,int v) {
        if (l>v||r<u) return {-inf,0};
        if (u<=l&&r<=v) return st[id];
        int mid=(l+r)/2;
        return merge_node(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
} Seg_tree;
struct Fenwick{
    int bit[N+5];
    void update(int u) {
        for (int idx=u;idx<=n;idx+=idx&(-idx)) bit[idx]++;
    }
    int get(int u) {
        int ans=0;
        for (int idx=u;idx>0;idx-=idx&(-idx)) ans+=bit[idx];
        return ans;
    }
} Fenwick_tree;
vector<int>res;
bool used[N+5];
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    Seg_tree.build(1,1,n);
    while (k>0) {
        int lo=1,hi=n,ans=1;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (mid-Fenwick_tree.get(mid)-1<=k) {
                ans=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        if (ans-Fenwick_tree.get(ans)-1>k) break;
        pair<int,int>temp=Seg_tree.get(1,1,n,1,ans);
        if (temp.second==0) break;
        res.push_back(temp.first);
        used[temp.second]=true;
        Seg_tree.update(1,1,n,temp.second);
        Fenwick_tree.update(temp.second);
        k-=temp.second-Fenwick_tree.get(temp.second);
    }
    for (auto i:res) cout<<i<<' ';
    for (int i=1;i<=n;i++)
        if (!used[i]) cout<<a[i]<<' ';
}
