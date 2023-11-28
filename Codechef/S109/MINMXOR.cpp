#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,t;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		int res=INT_MAX;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		int cur=a[1];
		for (int i=2;i<=n;i++) cur^=a[i];
		res=cur;
		for (int i=1;i<=n;i++) {
			int temp=(cur^a[i]);
			res=min(res,temp);
		}
		cout<<res<<'\n';
	}
}