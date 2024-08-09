#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,m;
long long x[N+5];
int bit[N+5];
int b[N+5],g[N+5],w[N+5];
int get(int idx) {
    int ans=0;
    while (idx>0) {
        ans+=bit[idx];
        idx-=idx&-idx;
    }
    return ans;
}
void update(int idx) {
    while (idx<=N) {
        bit[idx]++;
        idx+=idx&-idx;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>g[i];
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=n;i++) {
        x[1]++;
        x[b[i]+1]--;
        x[b[i]+1]+=2;
        x[b[i]+g[i]+1]-=2;
        x[b[i]+g[i]+1]+=5;
        x[b[i]+g[i]+w[i]+1]-=5;
    }
    for (int i=1;i<=N;i++) x[i]+=x[i-1];
    cin>>m;
    while (m--) {
        int h;
        cin>>h;
        int l=1,r=N;
        while (l<=r) {
            int mid=(l+r)/2;
            if (mid-get(mid)>=h) r=mid-1;
            else l=mid+1;
        }
        if (l-get(l)==h) {
            cout<<x[l]<<'\n';
            update(l);
        } else cout<<0<<'\n';
    }
}
