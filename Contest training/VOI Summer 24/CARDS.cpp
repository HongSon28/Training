#include<bits/stdc++.h>
using namespace std;
const int M=100;
long long mod=123456789;
int n,k,m;
int cnt0[M+5],cnt1[M+5];
void add(long long &x,long long y) {
	x+=y;
	if (x>=mod) x-=mod;
}
struct mat {
	int row,col;
	long long a[M+5][M+5];
};
mat matmul(mat x,mat y) {
	mat ans;
	ans.row=x.row;
	ans.col=y.col;
	for (int i=0;i<ans.row;i++) {
		for (int j=0;j<ans.col;j++) {
			ans.a[i][j]=0;
			for (int k=0;k<x.col;k++) add(ans.a[i][j],x.a[i][k]*y.a[k][j]%mod);
		}
	}
	return ans;
}
mat power(mat x,int y) {
	if (y==1) return x;
	mat ans=power(x,y/2);
	ans=matmul(ans,ans);
	if (y&1) ans=matmul(ans,x);
	return ans;
}
mat base0,base1,mul0,mul1;
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k>>m;	
    cnt1[0]--;
    for (int h=0;h<m;h++) {
    	cnt0[(2*h+1)%m]+=((k-1)/2)/m+1-(((k-1)/2)%m<h);
    	cnt1[(2*h)%m]+=(k/2)/m+1-((k/2)%m<h);
    }
    //for (int h=0;h<m;h++) cout<<cnt0[h]<<' '<<cnt1[h]<<endl;
    base0.row=base1.row=m,base0.col=base1.col=1;
    base0.a[0][0]=base1.a[0][0]=1;
    mul0.col=mul0.row=mul1.col=mul1.row=m;
    for (int i=0;i<m;i++) {
    	for (int j=0;j<m;j++) {
    		int t=(j-i+m)%m;
    		mul0.a[i][j]=cnt0[t];
    		mul1.a[i][j]=cnt1[t];
    	}
    }
    mat m0=power(mul0,(n+1)/2),m1=power(mul1,n/2);
    m0=matmul(m0,base0);
    m1=matmul(m1,base1);
    for (int i=0;i<m;i++) {
    	add(res,m0.a[i][0]*m1.a[(m-i)%m][0]%mod);
	}
    cout<<res;
}