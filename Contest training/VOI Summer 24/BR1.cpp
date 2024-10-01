#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
string s;
int n;
long long mod=1e9+7;
long long dp[N+5][N/2+5][2];
long long f(int i,int sum,bool les) {
	if (sum>n/2||sum<0) return 0;
    if (i==n) return sum==0;
    long long ans=0;
    if (dp[i][sum][les]!=-1) return dp[i][sum][les];
    if (sum+1>=0&&(les==true||'('<=s[i+1])) {
        ans+=f(i+1,sum+1,les||'('<s[i+1]);
        ans%=mod;
    }
    if (sum-1>=0&&(les==true||')'<=s[i+1])) {
        ans+=f(i+1,sum-1,les||')'<s[i+1]);
        ans%=mod;
    }
    dp[i][sum][les]=ans;
    return ans;
}
int main() {
    for (int i=0;i<=N;i++)
        for (int j=0;j<=N;j++)
            dp[i][j][0]=dp[i][j][1]=-1;
    cin>>s;
    n=s.size();
    s=' '+s;
    cout<<f(0,0,false);
}
