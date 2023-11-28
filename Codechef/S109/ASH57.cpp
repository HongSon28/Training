#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,t;
int a[N+5],b[N+5],cola[N+5],colb[N+5];
map<int,vector<int>>vc;
bool c[N*2+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n;
		vc.clear();
		for (int i=0;i<=2*n;i++) c[i]=false;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) {
			cin>>cola[i];
			vc[cola[i]].push_back(a[i]);
		}
		for (int i=1;i<=n;i++) cin>>b[i];
		for (int i=1;i<=n;i++) {
			cin>>colb[i];
			c[colb[i]]=true;
			vc[colb[i]].push_back(b[i]);
		}
		for (auto i=vc.begin();i!=vc.end();i++) {
			sort((i->second).begin(),(i->second).end(),greater<int>());
		}
		int last=0;
		bool flag=true;
		for (int i=1;i<=n;i++)  {
			if (c[cola[i]]) {
				while (!vc[cola[i]].empty()) {
					if (vc[cola[i]].back()<last) vc[cola[i]].pop_back();
					else break;
				}
				if (vc[cola[i]].empty()) {
					flag=false;
					break;
				} 
				last=vc[cola[i]].back();
				vc[cola[i]].pop_back();
			} else {
				if (a[i]<last) {
					flag=false;
					break;
				}
				last=a[i];
			}
		}
		if (flag) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}