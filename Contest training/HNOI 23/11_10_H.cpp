#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
pair<long long,long long>cd[N+5],ab[N+5];
vector<pair<long long,long long>>x,y;
long long rec(int l,int r,int u,int v) {
    if (u>v||l>r) return -1;
    int mid=(l+r)/2;
    long long ans=LLONG_MIN,pos=-1;
    for (int i=u;i<=v;i++) {
        long long temp=x[i].first-y[mid].first;
        if (temp<0) continue;
        temp*=(x[i].second-y[mid].second);
        if (ans<temp) {
            ans=temp;
            pos=i;
        }
    }
    //cout<<u<<' '<<v<<' '<<l<<' '<<r<<' '<<ans<<endl;
    return max({ans,rec(l,mid-1,u,pos),rec(mid+1,r,pos,v)});
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for (int i=1;i<=m;i++) cin>>cd[i].first>>cd[i].second;
    for (int i=1;i<=n;i++) cin>>ab[i].first>>ab[i].second;
    sort(cd+1,cd+1+m);
    long long last=cd[1].second;
    y.push_back(cd[1]);
    for (int i=2;i<=m;i++) {
        if (cd[i].second<=last) {
            last=cd[i].second;
            y.push_back(cd[i]);
        }
    }
    sort(ab+1,ab+1+n);
    last=ab[n].second;
    x.push_back(ab[n]);
    for (int i=n-1;i>=1;i--) {
        if (ab[i].second>=last) {
            last=ab[i].second;
            x.push_back(ab[i]);
        }
    }
    reverse(x.begin(),x.end());
    //for (auto p:y) cout<<p.first<<' '<<p.second<<endl;
    m=y.size(),n=x.size();
    cout<<max(0ll,rec(0,m-1,0,n-1));
}
