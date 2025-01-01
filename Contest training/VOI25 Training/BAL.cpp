#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n;
struct rect{
    int m;
    vector<pair<long long,long long>>p;
}a[N+5];
namespace sub1{
    bool check() {
        for (int i=1;i<=n;i++) {
            if (a[i].m!=4) return false;
            int cnt=0;
            for (int j=0;j<4;j++) {
                if (a[i].p[j].second==0) cnt++;
            }
            if (cnt!=2) return false;
        }
        return true;
    }
    pair<long long,long long>p[N+5];
    long long inf=1e18;
    vector<pair<long long,long long>>v1,v2;
    long long c1() {
        long long ans=0;
        for (int i=1;i<(int)v1.size();i++) ans+=v1[i].first-v1[i-1].second;
        return ans;
    }
    long long c2() {
        long long ans=0;
        for (int i=1;i<(int)v2.size();i++) ans+=v2[i-1].first-v2[i].second;
        return ans;
    }
    void solve() {
        for (int i=1;i<=n;i++) {
            long long mx=-inf,mn=inf;
            for (int j=0;j<4;j++) {
                if (a[i].p[j].second==0) {
                    mn=min(mn,a[i].p[j].first);
                    mx=max(mx,a[i].p[j].first);
                }
            }
            p[i]={mn,mx};
        }
        v1.push_back(p[1]),v2.push_back(p[1]);
        for (int i=2;i<=n;i++) {
            if (p[i].first>p[1].second) v1.push_back(p[i]);
            else v2.push_back(p[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        cout<<1000000ll*(min(c1(),c2())+c1()+c2());
    }
}
int main() {
    freopen("BAL.INP","r",stdin);
    freopen("BAL.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].m;
        for (int j=1;j<=a[i].m;j++) {
            pair<long long,long long>t;
            cin>>t.first>>t.second;
            a[i].p.push_back(t);
        }
    }
    sub1::solve();
}

