#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n,m;
char a[N+5][N+5];
int c[26][N+5][N+5];
bool dp[N+5][N+5];
long long res;
bool palind(int i,int j1,int j2) {
	int temp,cnt=0;
	for (int t=0;t<26;t++) {
		temp=c[t][i][j2]-c[t][i][j1-1];
		cnt+=(temp&1);
	}
	if ((j2-j1+1)&1) return (cnt==1);
	else return (cnt==0);
}
bool check(int i1,int i2,int j1,int j2) {
	for (int t=0;t<26;t++) {
		if ((c[t][i1][j2]-c[t][i1][j1-1])!=(c[t][i2][j2]-c[t][i2][j1-1])) return false;
	}
	return true;
}
int main() {
    //freopen("symetrictable.inp","r",stdin);
   // freopen("symetrictable.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		cin>>a[i][j];
    		for (int t=0;t<26;t++) c[t][i][j]=c[t][i][j-1];
    		c[a[i][j]-'a'][i][j]++;
    	}
    }
    for (int j1=1;j1<=m;j1++) {
    	for (int j2=j1;j2<=m;j2++) {
    		for (int i=1;i<=n;i++) {
    			dp[i][i]=palind(i,j1,j2);
    			res+=dp[i][i];
    		}
    		for (int i=1;i<n;i++) {
    			dp[i][i+1]=(check(i,i+1,j1,j2)&&dp[i][i]&&dp[i+1][i+1]);
    			res+=dp[i][i+1];
    		}
    		for (int len=3;len<=n;len++) {
    			for (int l=1;l+len-1<=n;l++) {
    				int r=l+len-1;
    				if (dp[l+1][r-1]&&check(l,r,j1,j2)&&dp[l][l]&&dp[r][r]) dp[l][r]=true;
    				else dp[l][r]=false;
    				res+=dp[l][r];
    			}
    		}
    	}
    }
    cout<<res;
}
