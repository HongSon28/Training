#include<bits/stdc++.h>
using namespace std;
int t;
long long a,b;
void solve(long long x,long long y) {
	while (x<=y) {
		if ((x%2)==(y%2)) {
			cout<<"YES"<<'\n';
			return;
		}
		x*=2;
	}
	cout<<"NO"<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>a>>b;
		solve(a,b);
	}
}