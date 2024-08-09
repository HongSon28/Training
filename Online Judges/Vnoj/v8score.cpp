#include<bits/stdc++.h>
using namespace std;
const int N=20,S=200;
int s,k,n;
int a[N+5][N+5];
bool dp[N+5][N+5][S+5];
int res[N+5];
void trace(int i) {
	int sum=s;
	for (int j=k;j>=1;j--) {
		res[j]=a[i][j];
		for (int last=1;last<=n;last++) {
			if (a[last][j-1]<=a[i][j]&&dp[last][j-1][sum-a[i][j]]) {
				sum-=a[i][j];
				i=last;
				break;
			}
		}
	}
	cout<<"YES"<<'\n';
	for (int i=1;i<=k;i++) cout<<res[i]<<' ';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s>>k>>n;
    for (int i=1;i<=n;i++) 
    	for (int j=1;j<=k;j++)
    		cin>>a[i][j];
    for (int i=1;i<=n;i++) {
    	a[i][0]=-1;
    	dp[i][0][0]=true;
    }
    for (int j=1;j<=k;j++) {
    	for (int i=1;i<=n;i++) {
    		for (int sum=s;sum>=a[i][j];sum--) {
    			for (int last=1;last<=n;last++) {
    				if (a[last][j-1]<=a[i][j]&&dp[last][j-1][sum-a[i][j]]) {
    					dp[i][j][sum]=true;
    					if (j==k&&sum==s) {
    						trace(i);
    						return 0;
    					}
    				}
    			}
    		}
    	}
    }
    cout<<"NO";
}