#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t;
long long a,b;
int d[N+5];
void seive() {
	iota(d,d+N+5,0);
    for (int i=2; i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (i<d[j]) d[j]=i;
    }
}
void solve1() {
	map<long long,long long>mp;
	while (a>1) {
		long long div=d[a],cnt=0;
		while (a%div==0) {
			a/=div;
			cnt++;
		}
		mp[div]+=cnt*2;
	}
	while (b>1) {
		long long div=d[b],cnt=0;
		while (b%div==0) {
			b/=div;
			cnt++;
		}
		mp[div]+=cnt*2;
	}
	long long res=1;
	for (auto i=mp.begin();i!=mp.end();i++) {
		res*=i->second+1;
	}
	cout<<res<<'\n';
}
void solve2() {
	map<long long,long long>mp;
	for (long long i=2;i*i<=a;i++) {
		long long cnt=0;
		while (a%i==0) {
			a/=i;
			cnt++;
		}
		mp[i]+=cnt*2;
	}
	if (a!=1) mp[a]+=2;
	for (long long i=2;i*i<=b;i++) {
		long long cnt=0;
		while (b%i==0) {
			b/=i;
			cnt++;
		}
		mp[i]+=cnt*2;
	}
	if (b!=1) mp[b]+=2;
	long long res=1;
	for (auto i=mp.begin();i!=mp.end();i++) {
		res*=i->second+1;
	}
	cout<<res<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	seive();
	cin>>t;
	while (t--) {
		cin>>a>>b;
		if (a>N||b>N) solve2();
		else solve1();
	}
}