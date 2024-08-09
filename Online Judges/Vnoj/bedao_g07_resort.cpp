#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,res;
int a[N+5];
bool p[N+5],chk1,chk2;
void seive() {
	memset(p,true,sizeof(p));
	p[0]=p[1]=false;
	for (int i=2;i*i<=N;i++) {
		if (p[i]==true) {
			for (int j=i*i;j<=N;j+=i) p[j]=false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	seive();
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]==2) chk2=true;
		else chk1=true;
	}
	sort(a+1,a+1+n);
	if (chk1&&chk2) {
		res=2;
		int sum=3;
		for (int i=n-1;i>1;i--) {
			sum+=a[i];
			res+=p[sum];
		}
	} else if (chk1) {
		int sum=0;
		for (int i=1;i<=n;i++) {
			sum+=a[i];
			res+=p[sum];
		}
	} else if (chk2) {
		res=1;
	}
	cout<<res;
}