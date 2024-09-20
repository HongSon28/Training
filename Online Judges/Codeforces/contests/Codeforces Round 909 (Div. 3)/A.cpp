#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t,n;
	cin>>t;
	while (t--) {
		cin>>n;
		if (n%3==0) cout<<"Second"<<'\n';
		else cout<<"First"<<'\n';
	}
}