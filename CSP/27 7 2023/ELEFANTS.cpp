#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
struct ele{
    int weight,iq,id;
    bool operator < (const ele &others) const {
        if (weight==others.weight) return iq>others.iq;
        return weight>others.weight;
    }
};
ele t[N+5];
pair<int,int> a[N+5];
vector<int>p(N+1),b(N+1,INT_MAX),trace(N+1),f(N+1),path;
int res,en;
int main() {
    freopen("ELEFANTS.INP","r",stdin);
    freopen("ELEFANTS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>t[i].weight>>t[i].iq;
        t[i].id=i;
    }
    sort(t+1,t+1+n);
    for (int i=1;i<=n;i++) {
        a[i].first=t[i].iq;
        a[i].second=t[i].id;
        //cout<<a[i].first<<' '<<a[i].second<<endl;
    }
    b[0]=INT_MIN;
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),a[i].first)-b.begin();
        trace[i]=p[k-1];
        b[k]=a[i].first;
        p[k]=i;
        f[i]=k;
    }
    for (int i=1;i<=n;i++) {
        if (res<f[i]) {
            res=f[i];
            en=i;
        }
    }
    cout<<res<<endl;
    for (int i=1;i<res;i++) {
        path.push_back(en);
        en=trace[en];
    }
    for (int i=0;i<path.size();i++) cout<<a[path[i]].second<<' ';
    cout<<a[en].second;
}
