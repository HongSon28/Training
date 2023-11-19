#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n;
pair<int,int>p[N+5];
int dp[N+5],cnt[N+5],mx,res;
int main() {
    freopen("ERASE.INP","r",stdin);
    freopen("ERASE.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p[i].first>>p[i].second;
        if (p[i].first>p[i].second) swap(p[i].first,p[i].second);
        dp[i]=1,cnt[i]=1;
    }
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++) {
            if (p[j].second<=p[i].first) {
                if (dp[i]<dp[j]+1) {
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                } else if (dp[i]==dp[j]+1) cnt[i]+=cnt[j];
            }
        }
        if (dp[i]>mx) {
            mx=dp[i];
            res=cnt[i];
        } else if (dp[i]==mx) res+=cnt[i];
    }
    cout<<n-mx<<' '<<res;
}
