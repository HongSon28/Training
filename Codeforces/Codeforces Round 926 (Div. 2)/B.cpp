#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>k;
		if (k==4*n-2) cout<<n*2<<'\n';
		else cout<<(k+1)/2<<'\n';
	}
}