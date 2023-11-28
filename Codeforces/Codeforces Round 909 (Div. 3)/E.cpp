#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n;
		bool flag=true;
		int mn=INT_MAX,pos;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			if (a[i]<mn) {
				mn=a[i];
				pos=i;
			}
		}
		for (int i=pos+2;i<=n;i++) {
			if (a[i]<a[i-1]) {
				flag=false;
				break;
			}
		}
		if (!flag) cout<<-1<<'\n';
		else cout<<pos-1<<'\n';
	}
}