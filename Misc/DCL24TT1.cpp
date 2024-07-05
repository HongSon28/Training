#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,x,k;
long long mod=1e9+7;
long long res[N+5];
void add(long long &x, long long y) {
	x+=y;
	if (x>=mod) x-=mod;
}
long long calc1(long long x) {
	long long c1=x,c2=x+1,c3=2*x+1,div=6;
	if (c1%2==0&&div%2==0) c1/=2,div/=2;
	if (c1%3==0&&div%3==0) c1/=3,div/=3;
	if (c2%2==0&&div%2==0) c2/=2,div/=2;
	if (c2%3==0&&div%3==0) c2/=3,div/=3;
	if (c3%2==0&&div%2==0) c3/=2,div/=2;
	if (c3%3==0&&div%3==0) c3/=3,div/=3;
	return (c1*c2%mod)*c3%mod;
}
long long calc2(long long x) {
	return (x*(x+1)/2)%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>x>>k;
    for (long long i=1;i<=n;i++) {
    	if (i>k) continue;
    	long long num=(k-i)/n;
    	res[i]=num*i*i%mod;
    	add(res[i],i*i%mod);
    	add(res[i],(n*n%mod)*calc1(num)%mod);
    	add(res[i],2*n*i%mod*calc2(num)%mod);
    	//cout<<num<<' '<<num*i*i%mod<<' '<<(n*n%mod)*calc1(num)%mod<<' '<<2*n*i%mod*calc2(num)%mod<<endl;
    }
    for (int i=1;i<=n;i++) {
    	int j=i-x+1;
    	if (j<1) j+=n;
    	cout<<res[j]<<' ';
    }
}