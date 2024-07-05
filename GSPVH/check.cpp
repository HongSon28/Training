#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,x,y;
map<int,int>id;
struct dat{
	int type,x,y;
} a[N+5];
vector<pair<int,int>>v;
int main() {
	freopen("check.inp","r",stdin);
	freopen("check.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	while (cin>>n) {
		if (n==-1) return 0;
		cin>>x>>y;
		for (int i=1;i<=n;i++) {
			char c;
			cin>>c>>a[i].x>>a[i].y;
			a[i].x-=x,a[i].y-=y;
			if (c=='R') a[i].type=1;
			else if (c=='B') a[i].type=2;
			else a[i].type=3;
		}
		v.clear();
		for (int i=1;i<=n;i++) if (a[i].x==0&&a[i].y>0) v.push_back({a[i].y,a[i].type});
		if (!v.empty()) {
			sort(v.begin(),v.end());
			if (v[0].second==1||v[0].second==3) {
				cout<<"YES"<<'\n';
				continue;
			}
		}
		v.clear();
		for (int i=1;i<=n;i++) if (a[i].x==0&&a[i].y<0) v.push_back({a[i].y,a[i].type});
		if (!v.empty()) {
			sort(v.rbegin(),v.rend());
			if (v[0].second==1||v[0].second==3) {
				cout<<"YES"<<'\n';
				continue;
			}
		}
		
		v.clear();
		for (int i=1;i<=n;i++) if (a[i].y==0&&a[i].x>0) v.push_back({a[i].x,a[i].type});
		if (!v.empty()) {
			sort(v.begin(),v.end());
			if (v[0].second==1||v[0].second==3) {
				cout<<"YES"<<'\n';
				continue;
			}
		}
		v.clear();
		for (int i=1;i<=n;i++) if (a[i].y==0&&a[i].x<0) v.push_back({a[i].x,a[i].type});
		if (!v.empty()) {
			sort(v.rbegin(),v.rend());
			if (v[0].second==1||v[0].second==3) {
				cout<<"YES"<<'\n';
				continue;
			}
		}
		
		v.clear();
		for (int i=1;i<=n;i++) if (a[i].x==a[i].y&&a[i].x>0) v.push_back({a[i].x,a[i].type});
		if (!v.empty()) {
			sort(v.begin(),v.end());
			if (v[0].second==2||v[0].second==3) {
				cout<<"YES"<<'\n';
				continue;
			}
		}
		v.clear();
		for (int i=1;i<=n;i++) if (a[i].x==a[i].y&&a[i].x<0) v.push_back({a[i].x,a[i].type});
		if (!v.empty()) {
			sort(v.rbegin(),v.rend());
			if (v[0].second==2||v[0].second==3) {
				cout<<"YES"<<'\n';
				continue;
			}
		}
		
		v.clear();
		for (int i=1;i<=n;i++) if (a[i].x==-a[i].y&&a[i].x>0) v.push_back({a[i].x,a[i].type});
		if (!v.empty()) {
			sort(v.begin(),v.end());
			if (v[0].second==2||v[0].second==3) {
				cout<<"YES"<<'\n';
				continue;
			}
		}
		v.clear();
		for (int i=1;i<=n;i++) if (a[i].x==-a[i].y&&a[i].x<0) v.push_back({a[i].x,a[i].type});
		if (!v.empty()) {
			sort(v.rbegin(),v.rend());
			if (v[0].second==2||v[0].second==3) {
				cout<<"YES"<<'\n';
				continue;
			}
		}
		
		cout<<"NO"<<'\n';
	}
}