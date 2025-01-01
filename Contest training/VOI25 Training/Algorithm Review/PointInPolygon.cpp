#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m;
long long x[N+5],y[N+5];
long long cross(long long x1,long long y1,long long x2,long long y2) {
	return x1*y2-x2*y1;
}
void solve() {
	bool fi;
	for (int i=1;i<=n;i++) {
		long long t=cross(x[i+1]-x[i],y[i+1]-y[i],x[0]-x[i],y[0]-y[i]);
		cout<<t<<endl;
		if (t==0) {
			cout<<"BOUNDARY"<<'\n';
			return;
		}
		if (i==1) fi=(t>0);
		else if ((t<0&&fi)||(t>0&&!fi)) {
			cout<<"OUTSIDE"<<'\n';
			return;
		}
	}
	cout<<"INSIDE"<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
	x[n+1]=x[1],y[n+1]=y[1];
	while (m--) {
		cin>>x[0]>>y[0];
		solve();
	}
}