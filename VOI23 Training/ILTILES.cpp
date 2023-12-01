#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long dp[N+5];
long long mod=1e9+7;
int t;
long long n;
void solve1() {
	dp[1]=1;
	dp[2]=2;
	for (int i=3;i<=n;i++) {
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=mod;
	}
	cout<<dp[n];
}
long long binpow(long long x,long long y) {
	if (y==0) return 0;
	if (y==1) return x%mod;
	long long k=binpow(x,y/2);
	k=(k*k)%mod;
	if (y%2==1) {
		k*=x;
		k%=mod;
	}
	return k;
}
void solve2() {
	if (n%3==0) cout<<binpow(2,n/3);
	else cout<<0;
}

struct mat{
    int x,y;
    long long a[5][5];
};
mat a,x;
mat operator * (mat a, mat b) {
    mat c;
    c.x=a.x,c.y=b.y;
    for (int i=1;i<=c.x;i++)
        for (int j=1;j<=c.y;j++)
            c.a[i][j]=0;
    for (int i=1;i<=a.x;i++) {
        for (int j=1;j<=b.y;j++) {
            for (int k=1;k<=a.y;k++) {
                c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
                c.a[i][j]%=mod;
            }
        }
    }
    return c;
}
mat power (mat a, long long x) {
    if (x==1) return a;
    mat temp=power(a, x/2);
    if (x%2==0) return temp*temp;
    else return temp*temp*a;
}
void solve3() {
	a.x=a.y=4;
    a.a[1][1]=a.a[1][3]=a.a[2][2]=a.a[3][1]=a.a[4][2]=a.a[1][4]=1;
    a.a[2][1]=2;
    x.x=4;
    x.y=1;
    x.a[1][1]=x.a[4][1]=2;
    x.a[2][1]=4;
    x.a[3][1]=1;
    if (n==1) {
    	cout<<1;
    	return;
    }
    if (n==2) {
    	cout<<2;
    	return;
    }
    mat res=(power(a,n-2)*x);
    cout<<res.a[1][1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>t;
	if (t==1) solve1();	
	else if (t==2) solve2();
	else solve3();
}