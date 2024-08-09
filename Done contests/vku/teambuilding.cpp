#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
string s;
long long res=0;
long long sum0[5001],sum1[5001];
long long dp[5001];
int main() {
    cin>>n>>k;
    cin>>s;
    s=" "+s;
    sum0[0]=0,sum1[0]=1;
    for (int i=1;i<=n;i++) {
        if (s[i]=='1') {
            sum1[i]=sum1[i-1]+1;
            sum0[i]=sum0[i-1];
        } else {
            sum1[i]=sum1[i-1];
            sum0[i]=sum0[i-1]+1;
        }
    }
    dp[0]=1;
    dp[1]=1;
    for (int i=2;i<=n;i++) {
        dp[i]=dp[i-1];
        for (int j=i-1;j>0;j--) {
            long long zero=sum0[i]-sum0[j-1];
            long long one=sum1[i]-sum1[j-1];
            if (abs(zero-one)<=k) {
                dp[i]+=dp[j-1];
                //cout<<j<<' '<<i<<endl;
                dp[i]%=1000000007;
            }
        }
    }
    //for (int i=0;i<=n;i++) cout<<dp[i]<< ' ';
    cout<<dp[n];
}
