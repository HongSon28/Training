#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5],b[N+5];
int cnt[(1<<22)+5];
int res;
int get(int l,int r) {
	if (l==0) return cnt[r];
	//cout<<l<<' '<<r<<' '<<cnt[r]<<' '<<cnt[l-1]<<endl;
	return cnt[r]-cnt[l-1];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=0;i<=21;i++) {
		for (int j=1;j<=n;j++) cnt[a[j]%(1<<(i+1))]++;
		for (int j=1;j<=(1<<(i+1));j++) cnt[j]+=cnt[j-1];
		int cur=0;
		for (int j=1;j<=n;j++) {
			int x=b[j]%(1<<(i+1));
			if (x<=(1<<i)) cur+=get((1<<i)-x,(1<<(i+1))-1-x);
			else cur+=get(0,(1<<(i+1))-1-x)+get((1<<i)-x+(1<<(i+1)),(1<<(i+1)));
			cur%=2;
			//cout<<i<<' '<<x<<' '<<cur<<endl;
		}
		res+=cur*(1<<i);
		for (int j=0;j<=(1<<(i+1));j++) cnt[j]=0;
	}
	cout<<res;
}