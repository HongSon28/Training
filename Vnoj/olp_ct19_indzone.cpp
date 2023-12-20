#include<bits/stdc++.h>
using namespace std;
long long n,mod=998244353;
struct mat{
	int row,col;
	long long a[3][3];
} x,a;
mat operator * (mat a,mat b) {
	mat c;
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
mat power (mat a,long long b) {
	if (b==1) return a;
	mat ans=power(a,b/2);
	ans=ans*ans;
	if (b%2==1) ans=ans*a;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    x.row=2,x.col=1;
    x.a[1][1]=x.a[2][1]=1;
    a.row=a.col=2;
    a.a[1][1]=a.a[2][1]=a.a[1][2]=1;
    cin>>n;
    if (n==0){
    	cout<<1;
    	return 0;
    }
    mat res=power(a,n)*x;
    cout<<(res.a[1][1]*res.a[2][1])%mod;
}