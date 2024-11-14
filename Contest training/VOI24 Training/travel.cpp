#include<bits/stdc++.h>
using namespace std;
long long n,x,y,u,v;
int main() {
	cin>>n>>x>>y>>u>>v;
	long long a=u-v;
	long long b=-n;
	long long c=y-x;
	cout<<a<<' '<<b<<' '<<c<<' '<<__gcd(a,b)<<endl;
	if (__gcd(a,b)!=c) {
		cout<<-1;
		return 0;
	}
	long long xa=1,ya=0,xb=0,yb=1,xr,yr;
	while (b!=0) {
		long long q=a/b;
		long long r=a%b;
		a=b;
		b=r;
		xr=xa-q*xb;
		yr=ya-q*yb;
		xa=xb,ya=yb;
		xb=xr,yb=yr;
	}
	cout<<xa<<' '<<ya;
}