#include<bits/stdc++.h>
using namespace std;
int t,n;
char c;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
	while (t--) {
		cin>>n;
		int mn=11,mx=0;
		for (int i=1;i<=n;i++) {
			cin>>c;
			if (c=='B') {
				mx=max(mx,i);
				mn=min(mn,i);
			}
		}
		if (mn==11) cout<<0<<'\n';
		else cout<<mx-mn+1<<'\n';
	}
}