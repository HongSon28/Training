#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m;
struct vec{
    vector<int>v;
    int id;
    bool operator < (const vec &other) const {
        for (int i=0;i<m;i++) {
            if (v[i]!=other.v[i]) return v[i]<other.v[i];
        }
    }
    bool operator >= (const vec &other) const {
        for (int i=0;i<m;i++) {
            if (v[i]<other.v[i]) return false;
        }
        return true;
    }
} a[N+5];
int dp[N+5],mx;
vector<int>group[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<m;j++) {
            int t;
            cin>>t;
            a[i].v.push_back(t);
        }
        a[i].id=i;
        sort(a[i].v.begin(),a[i].v.end());
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        dp[i]=1;
        for (int j=i-1;j>=1;j--) {
            if (a[i]>=a[j]) dp[i]=max(dp[j]+1,dp[i]);
        }
        mx=max(mx,dp[i]);
    }
    cout<<mx<<endl;
    for (int i=1;i<=n;i++) {
        group[dp[i]].push_back(a[i].id);
    }
    for (int i=1;i<=mx;i++) {
        cout<<group[i].size()<<' ';
        for (auto k:group[i]) cout<<k<<' ';
        cout<<'\n';
    }
}
