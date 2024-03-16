#include<bits/stdc++.h>
using namespace std;
int t,n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		if (n%2==1) {
			cout<<"NO"<<'\n';
			continue;
		}
		char c='A';
		cout<<"YES"<<'\n';
		for (int i=1;i<=n/2;i++) {
			cout<<c<<c;
			c++;
		}
		cout<<'\n';
	}
}