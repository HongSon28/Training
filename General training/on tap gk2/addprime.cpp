#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>prime;
bool p[5001];
int dp[5001][5001];
void sang() {
    memset(p,true,sizeof(p));
    p[0]=false;
    p[1]=false;
    for (int i=2;i<=n;i++) {
        if (p[i]==true) {
            for (int j=i*2;j<=n;j+=i){
                p[j]=false;
            }
        }
    }
    for (int i=2;i<=n;i++) {
        if (p[i]==true) prime.push_back(i);
    }
}
int main() {
    cin>>n;
    sang();
    for (int i=0;i<=n;i++) dp[i][0]=1;
    for (int i=1;i<=prime.size();i++) {
        for (int j=1;j<=n;j++) {
            if (prime[i-1]<=j) dp[i][j]=dp[i-1][j]+dp[i][j-prime[i-1]];
            else dp[i][j]=dp[i-1][j];
            dp[i][j]%=1000000007;
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    cout<<dp[prime.size()][n];

}
