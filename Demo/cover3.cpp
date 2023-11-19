#include<iostream>
#include<assert.h>
#include<vector>
#define MAXN 2000
using namespace std;
vector <int> a[MAXN];
int n,c[MAXN],l[MAXN];
long long int dp[2][MAXN][MAXN+1],sums[MAXN];
int cnt=0;
void dfs (int vr, int prev) {
    cnt++;
    bool flag=false;
    for (auto to : a[vr]) {
        if (to==prev) continue;
        //assert(flag==false);
        flag=true;
        dfs(to,vr);
    }

    for (int r=0; r<n; r++) {
        sums[r]=0;
        for (auto to : a[vr]) {
            if (to==prev) continue;
            sums[r]+=dp[1][to][r];
        }
        if (sums[r]>3e9+1) sums[r]=3e9;
        //cout << sums[r] << " ";
    }
    for (int r=0; r<l[vr]; r++) {
        if (sums[r]<3e9+1) dp[0][vr][r]=c[r]+sums[r];
    }
    for (auto to : a[vr]) {
        if (to==prev) continue;
        for (int r=0; r<n-1; r++) {
            dp[0][vr][r]=min(dp[0][vr][r],dp[0][to][r+1]+sums[r]-dp[1][to][r]);
        }
    }

    for (int r=0; r<n; r++) {
        dp[1][vr][0]=min(dp[1][vr][0],dp[0][vr][r]);
        //cout << dp[0][vr][r] << " ";
    }
    for (int r=1; r<n; r++) {
        dp[1][vr][r]=min(dp[1][vr][0],sums[r-1]);
    }

    //cout << (vr+1) << " " << dp[1][vr][0] << endl ;
}
int deg[MAXN];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    assert(cin >> n );
    assert((1<=n)&&(n<=MAXN));
    for (int i=0; i<n; i++) {
        assert(cin >> c[i] );
        assert((0<=c[i])&&(c[i]<=1e6));
    }
    for (int i=0; i<n; i++) {
        assert(cin >> l[i] );
        assert((0<=l[i])&&(l[i]<=n));
        //l[i]--;
    }
    int x,y;
    for (int i=0; i<n-1; i++) {
        assert(cin >> x >> y );
        assert((1<=x)&&(x<=n));
        assert((1<=y)&&(y<=n));
        x--; y--;
        a[x].push_back(y);
        a[y].push_back(x);
        deg[x]++; deg[y]++;
    }
    //char temp; assert(!(cin >> temp ));
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) {
            for (int h=0; h<n; h++) {
                dp[i][j][h]=3e9+1;
            }
        }
    }
    int start=0;
    for (int i=0; i<n; i++) {
        if (deg[i]==1) start=i;
    }
    dfs(start,-1);
    assert(cnt==n);
    if (dp[1][start][0]>=3e9) cout << -1 ;
    else cout << dp[1][start][0] ;
    cout << endl ;
    return 0;
}
