#include<bits/stdc++.h>
using namespace std;
int t;
long long a,b,c;
double mn;
long long res;
void solve1() {
	int lo=0,hi=1e9,ans=0;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		long long cur=a+(a+b)*mid;
		double temp=(double)cur/(mid*2+1);
		if (temp<=c) {
			ans=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	long long cur=a+(a+b)*ans;
	double temp=(double)cur/(ans*2+1);
	if (abs(temp-c)<mn) {
		mn=abs(temp-c);
		res=ans*2+1;
	}
	cur=a+(a+b)*(ans+1);
	temp=(double)cur/(ans*2+3);
	if (abs(temp-c)<mn) {
		mn=abs(temp-c);
		res=ans*2+3;
	}
}
void solve2() {
	int lo=0,hi=1e9,ans=0;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		long long cur=b+(a+b)*mid;
		double temp=(double)cur/(mid*2+1);
		if (temp>=c) {
			ans=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	long long cur=b+(a+b)*ans;
	double temp=(double)cur/(ans*2+1);
	if (abs(temp-c)<mn) {
		mn=abs(temp-c);
		res=ans*2+1;
	}
	cur=b+(a+b)*(ans+1);
	temp=(double)cur/(ans*2+3);
	if (abs(temp-c)<mn) {
		mn=abs(temp-c);
		res=ans*2+3;
	}
}
int main() {
	freopen("AVERSEG.INP","r",stdin);
	freopen("AVERSEG.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>a>>b>>c;
		if (a>b) swap(a,b);
		if (b<=c||a>=c) {
			cout<<1<<'\n';
			continue;
		}
		mn=abs((double)(a+b)/2-c);
		res=2;	
		solve1();
		solve2();
		cout<<res<<'\n';
	}
}