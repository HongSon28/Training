#include<bits/stdc++.h>
using namespace std;
const int N=16;
int n,k;
int a[N+5];
long long dp[N+1][(1<<16)+1],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=0;i<n;i++) {
    	cin>>a[i];
    	dp[i][(1<<i)]=1;
    }
    for (int mask=0;mask<(1<<n);mask++) {
    	for (int i=0;i<n;i++) {	
    		for (int j=0;j<n;j++) {
    			if (i==j) continue;
    			if ((mask>>i&1)||!(mask>>j&1)) continue;
    			if (abs(a[i]-a[j])>k) {
    				//cout<<i<<' '<<j<<' '<<mask<<' '<<dp[j][mask]<<' '<<(mask|(1<<i))<<endl;
    				dp[i][mask|(1<<i)]+=dp[j][mask];
    			}
    		}
    	}
    }
    for (int i=0;i<n;i++) res+=dp[i][(1<<n)-1];
    cout<<res;
}