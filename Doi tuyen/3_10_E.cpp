#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,k,res;
string s;
int dp[N*2+1][N*2+1][31][31];
int f(int x,int y,int u,int v,int turn) {
    if (dp[x][y][u][v]!=-1) return dp[x][y][u][v];
    if (u==0) {
        dp[x][y][u][v]=0;
       // cout<<x<<' '<<y<<' '<<u<<' '<<v<<' '<<turn<<' '<<dp[x][y][u][v][turn]<<endl;
        return 0;
    }
    if (v==0) {
        dp[x][y][u][v]=1;
       // cout<<x<<' '<<y<<' '<<u<<' '<<v<<' '<<turn<<' '<<dp[x][y][u][v][turn]<<endl;
        return 1;
    }
    if (turn==1) {
        dp[x][y][u][v]=max(f(x+1,y,u-(s[x]=='B'),v,0),f(x,y-1,u-(s[y]=='B'),v,0));
    } else {
        dp[x][y][u][v]=min(f(x+1,y,u,v-(s[x]=='B'),1),f(x,y-1,u,v-(s[y]=='B'),1));
    }
    //cout<<x<<' '<<y<<' '<<u<<' '<<v<<' '<<turn<<' '<<dp[x][y][u][v][turn]<<endl;
    return dp[x][y][u][v];
}
int main() {
    cin>>n>>k;
    cin>>s;
    s+=s;
    s=' '+s;
    memset(dp,-1,sizeof(dp));
    for (int i=1;i<=n;i++) res+=f(i,i+n-1,k,k,1);
    cout<<res;
}
