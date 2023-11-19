#include<bits/stdc++.h>
using namespace std;
const int N=4e3;
int n;
int a[N+5];
int res;
int dp[N+5][N+5];
map<int,vector<int>>mp;
int bs(int l,int m) {
    int lo=0,hi=mp[m].size()-1;
    int r=-1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (mp[m][mid]>=l) {
            r=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    return r;
}
int main() {
    freopen("LAS2.INP","r",stdin);
    freopen("LAS2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<i;j++)
            dp[i][j]=2;
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++) {
            int k=bs(i+1,a[i]+a[i]-a[j]);
            if (k!=-1) {
                dp[mp[a[i]+a[i]-a[j]][k]][i]=max(dp[i][j]+1,dp[mp[a[i]+a[i]-a[j]][k]][i]);
                //cout<<j<<' '<<i<<' '<<mp[a[i]+a[i]-a[j]][k]<<endl;
            }
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<i;j++) res=max(res,dp[i][j]);
    cout<<res;
}
