#include<bits/stdc++.h>
using namespace std;
long long n;
long long mod=1e9+7;
struct matrix{
	long long a[2][2];
} base,f;
matrix mul(matrix x,matrix y) {
	matrix ans;
	for (int i=0;i<2;i++) {
		for (int j=0;j<2;j++) {
			ans.a[i][j]=0;
			for (int k=0;k<2;k++) {
				ans.a[i][j]+=x.a[i][k]*y.a[k][j];
				if (ans.a[i][j]>=mod*mod) ans.a[i][j]-=mod*mod;
			}
			ans.a[i][j]%=mod;
		}
	}
	return ans;
}
matrix power(matrix x,long long y) {
	matrix ans;
	ans.a[0][0]=ans.a[1][1]=1;
	ans.a[1][0]=ans.a[0][1]=0;
	while (y) {
		if (y&1) ans=mul(ans,x);
		y>>=1;
		x=mul(x,x);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    f.a[1][1]=f.a[0][1]=f.a[1][0]=1;
    cin>>n;	
    f=power(f,n);
    cout<<f.a[1][0];
}