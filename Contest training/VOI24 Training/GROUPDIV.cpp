#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
vector<int>v[N+5];
int g[N+5];
int d[N+5];
queue<int>q;
int main() {
    freopen("GROUPDIV.INP","r",stdin);
    freopen("GROUPDIV.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        int t,x;
        cin>>t;
        d[i]=t;
        while (t--) {
            cin>>x;
            v[i].push_back(x);
        }
        if (d[i]>1) q.push(i);
    }
    while (!q.empty()) {
        int t=q.front();
        q.pop();
        if (d[t]<=1) continue;
        //cout<<t<<' '<<d[t]<<' '<<g[t]<<endl;
        if (g[t]==0) {
            g[t]=1;
            for (auto x:v[t]) {
                if (g[x]==0) d[x]--;
                else d[x]++;
                if (d[x]>1) q.push(x);
            }
        } else {
            g[t]=0;
            for (auto x:v[t]) {
                if (g[x]==1) d[x]--;
                else d[x]++;
                if (d[x]>1) q.push(x);
            }
        }
        d[t]=v[t].size()-d[t];
    }
    vector<int>g0,g1;
    for (int i=1;i<=n;i++) {
        if (g[i]==0) g0.push_back(i);
        else g1.push_back(i);
    }
    cout<<"YES"<<'\n';
    for (auto i:g0) cout<<i<<' ';
    cout<<'\n';
    for (auto i:g1) cout<<i<<' ';
}
