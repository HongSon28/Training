#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<int,int> a[N+5];
int pos[N+5];
vector<int>b(N+1,INT_MAX),f(N+1),trace(N+5),p(N+5),path;
int res,en;
int main() {
    freopen("LINES.INP","r",stdin);
    freopen("LINES.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        int temp;
        cin>>temp;
        pos[temp]=i;
    }
    for (int i=1;i<=n;i++) {
        cin>>a[i].second;
        a[i].first=pos[a[i].second];
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
    cout<<a[en].second<<' ';
    for (int i=path.size()-1;i>=0;i--) cout<<a[path[i]].second<<' ';
}
