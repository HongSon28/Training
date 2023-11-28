#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,mx;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>a>>b>>c;
		if ((b%2)==(c%2)) cout<<1<<' ';
		else cout<<0<<' ';
		if ((a%2)==(c%2)) cout<<1<<' ';
		else cout<<0<<' ';
		if ((a%2)==(b%2)) cout<<1<<'\n';
		else cout<<0<<'\n';
	}
}