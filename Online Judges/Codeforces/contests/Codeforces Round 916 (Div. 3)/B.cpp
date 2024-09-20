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
		int cur=n-k;
		for (int i=1;i<=n-k;i++) {
			cout<<cur<<' ';
			cur--;
		}
		cur=n-k+1;
		for (int i=1;i<=k;i++) {
			cout<<cur<<' ';
			cur++;
		}
		cout<<'\n';
	}
}