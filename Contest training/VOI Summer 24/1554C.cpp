#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>m;
		m++;
		int res=0;
		for (int i=30;i>=0;i--) {
			int bn=(n>>i&1),bm=(m>>i&1);
			if (!bn&&bm) res|=(1<<i);
			if (bn&&!bm) break;
		}
		cout<<res<<'\n';
	}
}