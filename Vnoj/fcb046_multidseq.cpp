#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,k,mod=1e9+7,res;
long long dp[51][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) dp[1][i]=1;
    for (int i=1;i<k;i++) {
    	for (int j=1;j<=n;j++) {
    		for (int k=j;k<=n;k+=j) {
    			dp[i+1][k]+=dp[i][j];
    			dp[i+1][k]%=mod;
    		}
    	}
    }
    for (int i=1;i<=n;i++) {
    	res+=dp[k][i];
    	res%=mod;
    }
    cout<<res;
}