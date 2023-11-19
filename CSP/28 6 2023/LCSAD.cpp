#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,m;
string s,t;
int dp[N+5][N+5];
vector<vector<int>>v(100);
int res;
int bs(int id,int mn) {
    int lo=0,hi=v[id].size()-1;
    int t=m+5;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (v[id][mid]>mn) {
            t=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    if (t==m+5) return m+5;
    return v[id][t];
}
int main() {
    freopen("LCSAD.INP","r",stdin);
    freopen("LCSAD.OUT","w",stdout);
    cin>>n>>m;
    cin>>s>>t;
    s=' '+s,t=' '+t;
    for (int i=1;i<=m;i++) v[t[i]-'a'].push_back(i);
    for (int i=0;i<=n;i++)
        for (int j=1;j<=n;j++)
            dp[i][j]=m+5;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            int k=bs(s[i]-'a',dp[i-1][j-1]);
            dp[i][j]=min(dp[i-1][j],k);
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (dp[i][j]<=m&&j>res) res=j;
        }
    }
    cout<<res;
}
