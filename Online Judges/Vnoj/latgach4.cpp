#include<bits/stdc++.h>
using namespace std;
int t;
long long n,mod=111539786;
struct matrix{
	int row,col;
	long long a[3][3];
	
} a;
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
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    a.col=a.row=2;
    a.a[1][1]=a.a[1][2]=a.a[2][1]=1;
    a.a[2][2]=0;
    while (t--) {
    	cin>>n;
    	if (n==1) {
    		cout<<1<<'\n';
    		continue;
    	}
    	matrix temp=power(a,n-1);
    	cout<<(temp.a[1][1]+temp.a[1][2])%mod<<'\n';
    }
}