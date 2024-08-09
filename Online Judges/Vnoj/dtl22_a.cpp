#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n;
int l[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		int sum=0;
		bool flag=false;
		for (int i=1;i<=n;i++) {
			cin>>l[i];
			sum+=l[i];
		}
		sort(l+1,l+1+n,greater<int>());
		for (int i=1;i<=n;i++) {
			if (l[i]<sum-l[i]) {
				cout<<sum<<'\n';
				flag=true;
				break;
			}
			sum-=l[i];
		}
		if (!flag) cout<<0<<'\n';
	}
}