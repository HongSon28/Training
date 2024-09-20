#include<bits/stdc++.h>
using namespace std;
const int N=50;
int t,n;
int a[N+5];
bool check(int x) {
	int t=10;
	while (x>0) {
		if (x%10>t) return false;
		t=x%10;
		x/=10;
	}
	return true;
}
void solve() {
	int cur=100;
	for (int i=n;i>=1;i--) {
		if (a[i]<=cur) cur=a[i];
		else {
			if (!check(a[i])) {
				cout<<"NO"<<'\n';
				return;
			} else {
				while (a[i]>0) {
					if (a[i]%10>cur){
						cout<<"NO"<<'\n';
						return;
					} 
					cur=min(cur,a[i]%10);
					a[i]/=10;
				}
			}
		}
	}
	cout<<"YES"<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		solve();
	}
}