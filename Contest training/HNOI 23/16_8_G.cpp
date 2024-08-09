#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n;
int a[N+5];
int dp[(1<<N)+5][N+5],cnt[(1<<N)+5][N+5];
int main() {
    while (cin>>n) {
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        if (n==0) return 0;
        for (int i=0;i<n;i++) cin>>a[i];
        for (int bit=0;bit<(1<<n);bit++) {
            for (int i=0;i<n;i++) {
                if ((bit>>i&1)==0) continue;
                int last=bit&~(1<<i);
                if (last==0) {
                    dp[bit][i]=a[i]*2;
                    cnt[bit][i]=1;
                } else {
                    for (int j=0;j<n;j++) {
                        if (last>>j&1) {
                            if (dp[bit][i]==dp[last][j]-a[j]+abs(a[i]-a[j])+a[i]) cnt[bit][i]+=cnt[last][j];
                            if (dp[bit][i]<dp[last][j]-a[j]+abs(a[i]-a[j])+a[i]) {
                                dp[bit][i]=dp[last][j]-a[j]+abs(a[i]-a[j])+a[i];
                                cnt[bit][i]=cnt[last][j];
                            }
                        }
                    }
                }
            }
        }
        int mx=0,cc;
        int full=(1<<n)-1;
        for (int i=0;i<n;i++){
            if (dp[full][i]>mx) {
                mx=dp[full][i];
                cc=cnt[full][i];
            } else if (dp[full][i]==mx) cc+=cnt[full][i];
        }
        cout<<mx+2*n<<' '<<cc<<'\n';
    }
}
