#include<bits/stdc++.h>
using namespace std;
const int N=1e3,maxN=1e4;
int n,a,b,d;
pair<int,int>p[N+5];
int dp[N+5][maxN+5];
int inf=1e9,res=inf,sum;
bool comp(pair<int,int>a,pair<int,int>b) {
    double x=(double)a.second/(double)a.first;
    double y=(double)b.second/(double)b.first;
    return x>y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>a>>b>>d;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n,comp);
    for (int i=0;i<=N;i++)
        for (int j=0;j<=maxN;j++)
            if (i!=0) dp[i][j]=inf;
    for (int i=0;i<n;i++) {
        for (int l=a;l<=b;l++) {
            int r=l+sum;
            int l1=l-p[i+1].first,r1=r;
            int l2=l,r2=r+p[i+1].first;
            if (l1>=a&&r1<=b) dp[i+1][l1]=min(dp[i+1][l1],dp[i][l]+abs(d-l)*p[i+1].second);
            if (l2>=a&&r2<=b) dp[i+1][l2]=min(dp[i+1][l2],dp[i][l]+abs(r2-d)*p[i+1].second);
        }
        sum+=p[i+1].first;
    }
    for (int i=a;i<=b;i++) res=min(res,dp[n][i]);
    cout<<res;
}
