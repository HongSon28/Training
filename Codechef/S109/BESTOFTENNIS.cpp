#include<bits/stdc++.h>
using namespace std;
int t,x,y;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>x>>y;
		x=max(x,y);
		cout<<x*2-1<<'\n';
	}
}