#include<bits/stdc++.h>

const int mx = 10000;
using namespace std;
bool cmp(pair<int,int> x, pair<int,int> y){return x.second < y.second;}
int main(){
    int n;
    pair <int,int> a[mx];
    int dp[mx];
    int res = 1;
    cin >> n;
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++)
            if(a[j].second <= a[i].first)
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
        res=max(res,dp[i]);
    }
    cout<<res;
    return 0;
}
