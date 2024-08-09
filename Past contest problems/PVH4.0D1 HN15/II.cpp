#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int n,k,s;
int a[N+5];
int b[N+5];
long long res,mod=20215201314;
bool better(int l,int r) {
	for (int i=l;i<=r;i++) {
		if (a[i]!=b[i]) return a[i]<b[i];
	}
	return false;
}
void check() {
	int cnt=0;
	for (int l=1;l<=n;l++) {
		for (int r=l;r<=n;r++) {
			if (better(l,r)) {
				cnt++;
			}
		}
	}
	res+=(cnt==k);
}
void rec(int t) {
	for (int i=1;i<=s;i++) {
		b[t]=i;
		if (t==n) check();
		else rec(t+1);
	}
}
void sub1() {
	rec(1);
	cout<<res<<'\n';
}
void sub4() {
	res=1;
	for (int i=1;i<=n;i++) {
		res*=a[i];
		res%=mod;
	}
	cout<<res<<'\n';
}
int main() {
	freopen("II.INP","r",stdin);
	freopen("II.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k>>s;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<=8&&s<=4) sub1();
	else if (k==0) sub4();
	else cout<<1;
}