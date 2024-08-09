#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
int h[N+5];
int dp[N+5][N+5];
long long mod=1e9+7;
long long res;
int main() {
    //freopen("PROLINE.INP","r",stdin);
    //freopen("PROLINE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (h[i]>=h[j]) continue;
            long long len=2,mul=1,cur=1;
            int last=h[j];
            for (int k=j+1;k<=n;k++) {
                if (h[k]-last==h[j]-h[i]) {
                    len++;
                    last=h[k];
                    mul*=cur;
                    mul%=mod;
                    cur=1;
                } else if (h[k]==last&&h[k]!=h[j]) cur++;
            }
            res+=(len-2)*mul%mod;
            res%=mod;
        }
    }
    cout<<res;
}
