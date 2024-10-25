#include<bits/stdc++.h>
using namespace std;
int t,n;
long long mod=1e9+7;
struct matrix{
	int row,col;
	long long a[2][2];
}x,mat1,mat2;
matrix mul(matrix x, matrix y, long long mod) {
	matrix ans;
	ans.row=x.row,ans.col=y.col;
	for (int i=0;i<ans.row;i++) {
		for (int j=0;j<ans.col;j++) {
			ans.a[i][j]=0;
			for (int k=0;k<x.col;k++) {
				ans.a[i][j]+=x.a[i][k]*y.a[k][j];
				if (ans.a[i][j]>=mod*mod) ans.a[i][j]-=mod*mod;
			}
			ans.a[i][j]%=mod;
		}
	}
	return ans;
}
matrix power(matrix x,long long y,long long mod) {
	matrix ans=x;
	y--;
	while (y>0) {
		if (y&1) ans=mul(ans,x,mod);
		y/=2;
		x=mul(x,x,mod);
	}
	return ans;
}
long long power(long long x,long long y) {
	long long ans=1;
	while (y>0) {
		if (y&1) ans=(ans*x)%mod;
		y/=2;
		x=(x*x)%mod;
	}
	return ans;
}
long long solve() {
	if (n==0) return 0;
	if (n==1) return 1;
	long long l1=mul(power(x,n-1,mod-1),mat1,mod-1).a[0][0]-2;
	if (l1<0) l1+=mod-1;
	matrix mt=power(x,n-1,mod);
	long long cnt=mul(mt,mat2,mod).a[0][0];
	long long l2=mul(mt,mat1,mod).a[0][0]+1;
	if (l2>=mod) l2-=mod;
	matrix temp=power(x,n-1,mod);
	temp=mul(temp,mat1,mod);
	return power(2,l1)*l2%mod*cnt%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    x.row=x.col=2;
    x.a[0][0]=x.a[0][1]=x.a[1][0]=1;
    x.a[1][1]=0;
    mat1.row=mat2.row=2,mat1.col=mat2.col=1;
    mat1.a[0][0]=mat1.a[1][0]=mat2.a[0][0]=1;
    mat2.a[1][0]=0;
    cin>>t;
    while (t--) {
    	cin>>n;
    	cout<<solve()<<'\n';
    }	
}