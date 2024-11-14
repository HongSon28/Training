#include<bits/stdc++.h>
using namespace std;
int t,x,y,k;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>x>>y>>k;
		x=min(x,y);
		cout<<0<<' '<<0<<' '<<x<<' '<<x<<'\n';
		cout<<0<<' '<<x<<' '<<x<<' '<<0<<'\n';
	}
}