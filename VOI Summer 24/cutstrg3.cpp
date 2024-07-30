#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int k,n;
string s1,s2;
int dp[N+5][N+5];
int res;
bool ok(int l1,int r1,int l2,int r2,int l3,int r3) {
	int len1=r1-l1+1;
	int len2=r2-l2+1;
	int len3=r3-l3+1;
	return (dp[len1][r1]>=len1 && dp[len1+len2][r2]>=len2 && dp[n][r3]>=len3);
}
bool check(int i,int j) {
	return (ok(1,i,i+1,j,j+1,n) || ok(1,i,j+1,n,i+1,j) ||
			ok(i+1,j,1,i,j+1,n) || ok(i+1,j,j+1,n,1,i) ||
			ok(j+1,n,1,i,i+1,j) || ok(j+1,n,i+1,j,1,i));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>k>>s1>>s2;
    n=s1.size();
    s1=' '+s1;
    s2=' '+s2;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) {
    		int temp=abs(s1[i]-s2[j]);
    		if (temp<=k) dp[i][j]=dp[i-1][j-1]+1;
    	}
    }
	for (int i=1;i<n;i++) 
		for (int j=i+1;j<n;j++) 
			res+=check(i,j);
	cout<<res;
}