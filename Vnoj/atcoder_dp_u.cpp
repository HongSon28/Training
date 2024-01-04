#include<bits/stdc++.h>
using namespace std;
const int N=16;
int n;
long long a[N][N];
long long cost[1<<N],dp[1<<N];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=0;i<n;i++) 
		for (int j=0;j<n;j++)
			cin>>a[i][j];
	for (int i=0;i<(1<<n);i++) {
		for (int j=0;j<n;j++) {
			for (int k=j+1;k<n;k++) {
				if ((i>>j&1)&&(i>>k&1)) cost[i]+=a[j][k];
			}
		}
	}
	for (int mask=0;mask<(1<<n);mask++) {
		int m=((1<<n)-1)^mask;
		for (int mask2=m;mask2;mask2=(mask2-1)&m) {
			dp[mask2|mask]=max(dp[mask2|mask],dp[mask]+cost[mask2]);
		}
	}
	cout<<dp[(1<<n)-1];
}