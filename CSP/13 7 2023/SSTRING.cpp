#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string s;
int n;
int res;
int c[N+5];
bool a[N+5];
vector<vector<pair<int,int>>>v(N+5);
bool check(int m) {
    memset(a,false,sizeof(a));
    for (int i=1;i<=n-m+1;i++) {
        int r=i+m-1;
        int t=c[r]-c[i-1];
        //cout<<i<<' '<<r<<' '<<t<<endl;
        if (!a[t]) a[t]=true;
        else return true;
    }
    return false;
}
int main() {
    freopen("SSTRING.INP","r",stdin);
    freopen("SSTRING.OUT","w",stdout);
    cin>>s;
    n=s.size();
    s=' '+s;
    for (int i=1;i<=n;i++) c[i]=c[i-1]+(s[i]=='1');
    int lo=1,hi=n;
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            lo=mid+1;
            res=mid;
        } else hi=mid-1;
    }
    for (int i=1;i<=n-res+1;i++) {
        int r=i+res-1;
        int t=c[r]-c[i-1];
        //cout<<i<<' '<<r<<' '<<t<<endl;
        v[t].push_back({i,r});
    }
    for (int i=0;i<=N;i++) {
        if (v[i].size()>=2) {
            cout<<v[i][0].first<<' '<<v[i][0].second<<' '<<v[i][1].first<<' '<<v[i][1].second;
            return 0;
        }
    }
}
