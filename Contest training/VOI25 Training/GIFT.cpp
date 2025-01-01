#include<bits/stdc++.h>
using namespace std;
const int N=100;
int a,b,c;
bool dp[N+5][N+5][N+5];
pair<int,int> trace[N+5][N+5][N+5];
vector<int>v1,v2;
void tr(int a,int b,int c) {
    if (a==0&&b==0&&c==0) return;
    pair<int,int>p=trace[a][b][c];
    v1.push_back(p.first),v2.push_back(p.second);
    tr(a-p.first*p.first,b-p.second*p.second,c-p.first*p.second);
}
void solve() {
    memset(trace,-1,sizeof(trace));
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=true;
    v1.clear(),v2.clear();
    cin>>a>>b>>c;
    for (int i=1;i<=a;i++) {
        for (int j=1;j<=b;j++) {
            for (int k=1;k<=c;k++) {
                for (int x=0;x*x<=i;x++) {
                    for (int y=0;y*y<=j;y++) {
                        if (x*y>k||dp[i][j][k]) break;
                        if (!dp[i-x*x][j-y*y][k-x*y]) continue;
                        dp[i][j][k]=true;
                        trace[i][j][k]={x,y};
                    }
                }
            }
        }
    }
    tr(a,b,c);
    cout<<v1.size()<<'\n';
    for (auto x:v1) cout<<x<<' ';
    cout<<'\n';
    for (auto x:v2) cout<<x<<' ';
    cout<<'\n';
}
int main() {
    freopen("GIFT.INP","r",stdin);
    freopen("GIFT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    solve();
}

