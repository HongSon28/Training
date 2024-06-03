#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a,b,c,n,mod;
struct matrix{
	int row,col;
	long long a[4][4];
	
} ma,f;
matrix operator * (matrix a,matrix b) {
	matrix c;
	c.row=a.row;
	c.col=b.col;
	for (int i=1;i<=c.row;i++) {
		for (int j=1;j<=c.col;j++) {
			c.a[i][j]=0;
			for (int k=1;k<=a.col;k++) {
				c.a[i][j]+=(a.a[i][k]*b.a[k][j])%mod;
				c.a[i][j]%=mod;
			}
		}
	}
	return c;
}
matrix power (matrix a,long long b) {
	if (b==1) return a;
	matrix temp=power(a,b/2);
	temp=temp*temp;
	if (b%2==1) temp=temp*a;
	return temp;
}
long long dp[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    ma.col=ma.row=3;
    ma.a[2][1]=ma.a[3][2]=1;
    f.row=3;
    f.col=1;
    f.a[1][1]=3;
    f.a[2][1]=2;
    f.a[3][1]=1;
    while (cin>>a>>b>>c>>mod>>n) {
    	if (n<=N) {
    		dp[1]=1%mod;
    		dp[2]=2%mod;
    		dp[3]=3%mod;
    		for (int i=4;i<=n;i++) {
    			if (i%3==1) dp[i]=(a*dp[i-1]%mod+b*dp[i-2]%mod+c*dp[i-3]%mod)%mod;
    			else if (i%3==2) dp[i]=(a*dp[i-3]%mod+b*dp[i-1]%mod+c*dp[i-2]%mod)%mod;
    			else dp[i]=(a*dp[i-2]%mod+b*dp[i-3]%mod+c*dp[i-1]%mod)%mod;
    		}
    		cout<<dp[n]<<'\n';
    		continue;
    	}
    	ma.a[1][1]=a;
    	ma.a[1][2]=b;
    	ma.a[1][3]=c;
    	if (n<=3) {
    		cout<<n%mod<<'\n';
    		continue;
    	}
    	matrix temp=power(ma,n-3)*f;
    	/*
    	matrix xx=power(ma,n-3);
    	for (int i=1;i<=xx.row;i++){
    		for (int j=1;j<=xx.col;j++) cout<<xx.a[i][j]<<' ';
    		cout<<endl;
    	}
    	cout<<endl;
    	for (int i=1;i<=f.row;i++){
    		for (int j=1;j<=f.col;j++) cout<<f.a[i][j]<<' ';
    		cout<<endl;
    	}
    	cout<<endl;
    	for (int i=1;i<=temp.row;i++){
    		for (int j=1;j<=temp.col;j++) cout<<temp.a[i][j]<<' ';
    		cout<<endl;
    	}
    	if (n%3==1) cout<<temp.a[3][1]<<'\n';
    	else if (n%3==2) cout<<temp.a[2][1]<<'\n';
    	else cout<<temp.a[1][1]<<'\n';
    	*/
    	//cout<<temp.a[1][1]<<'\n';
    }
}