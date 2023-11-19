#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=31;
int dp[N+1][2][N+1][2];
string s;
int f(int i, bool les, int cnt, int nz) {
    if (i==m) return cnt==k&&nz==1;
    int ans=0;
    if (dp[i][les][cnt][nz]!=-1) return dp[i][les][cnt][nz];
    if (nz==1) {
        if (cnt+1<=k&&(les||'0'<=s[i+1])) ans+=f(i+1,les||'0'<s[i+1],cnt+1,1);
    }
    else
        ans+=f(i+1,les||'0'<s[i+1],cnt,0);
    if (cnt<=k&&(les||'1'<=s[i+1])) ans+=f(i+1,les||'1'<s[i+1],cnt,1);
    dp[i][les][cnt][nz]=ans;
    return ans;
}
int main() {
    freopen("CZERO.INP","r",stdin);
    freopen("CZERO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin>>n>>k) {
        s.clear();
        for (int i=0;i<=N;i++) {
            for (int j=0;j<=1;j++) {
                for (int m=0;m<=N;m++) {
                    dp[i][j][m][0]=dp[i][j][m][1]=-1;
                }
            }
        }
        for (int i=31;i>=0;i--) {
            s+=to_string(n>>i&1);
        }
        m=s.size();
        s=' '+s;
        cout<<f(0,0,0,0)<<'\n';
    }
}
