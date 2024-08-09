#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],last[N+5],res,mx;
vector<long long>cprs,ll[N+5];
long long mod=1e9+7;
pair<long long,long long>st[N*4+5],b[N+5];
vector<pair<int,pair<long long,long long>>>v;
pair<long long,long long> get(int id,int l,int r,int u,int v) {
    if (l>v||r<u) return {0,0};
    if (u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    pair<long long,long long>get1=get(id*2,l,mid,u,v),get2=get(id*2+1,mid+1,r,u,v);
    if (get1.first>get2.first) return get1;
    else if (get1.first<get2.first) return get2;
    else return {get1.first,(get1.second+get2.second)%mod};
}
void update (int id,int l,int r,int pos,long long len, long long way) {
    if (l>pos||r<pos) return;
    if (l==r) {
        if (st[id].first==len) {
            st[id].second+=way;
            st[id].second%=mod;
        }
        else if (st[id].first<len) st[id]={len,way};
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,len,way);
    update(id*2+1,mid+1,r,pos,len,way);
    if (st[id*2].first>st[id*2+1].first) st[id]=st[id*2];
    else if (st[id*2].first<st[id*2+1].first) st[id]=st[id*2+1];
    else {
        st[id].first=st[id*2].first;
        st[id].second=(st[id*2].second+st[id*2+1].second)%mod;
    }
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        cprs.push_back(a[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) {
        a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
        if (!ll[a[i]].empty()) last[i]=ll[a[i]].back();
        ll[a[i]].push_back(i);
        b[i]={a[i],i};
    }
    sort(b+1,b+1+n);
    long long pr=0;
    for (int i=1;i<=n;i++) {
        int val=b[i].first, pos=b[i].second;
        //cout<<val<<' '<<pos<<' '<<pr<<endl;
        if (val!=pr) {
            for (auto p:v) {
                //cout<<p.first<<' '<<p.second.first<<' '<<p.second.second<<endl;
                update(1,1,n,p.first,p.second.first,p.second.second);
            }
            v.clear();
        }
        pr=val;
        pair<long long,long long>temp=get(1,1,n,last[pos]+1,pos-1);
       // cout<<i<<' '<<pos<<' '<<last[pos]+1<<' '<<pos-1<<' '<<temp.first<<' '<<temp.second<<endl;
        long long way=temp.second;
        if (temp.first==0) {
            if (last[pos]==0) way=1;
            else way=0;
        }
        if (temp.first+1>mx) {
            mx=temp.first+1;
            res=way;
        } else if(temp.first+1==mx){
            res+=way;
            res%=mod;
        }
        v.push_back({pos,{temp.first+1,way}});
    }
    cout<<res;
}

