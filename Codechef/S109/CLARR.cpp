#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,t,d;
long long a[N+5],b[N+5],c[N+5];
vector<pair<int,int>>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		v.clear();
		bool flag=true;
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>b[i];
		for (int i=1;i<=n;i++) cin>>c[i];
		a[1]=b[1];
		for (int i=1;i<=n;i++) {
			if (b[i]<c[i]) {
				flag=false;
				break;
			}
		}
		if (b[1]!=c[1]||!flag) {
			cout<<"NO"<<'\n';
			continue;
		}
		v.push_back({1,0});
		for (int i=2;i<=n;i++) {	
			if (b[i]!=b[i-1]&&c[i]!=c[i-1]) {
				flag=false;
				break;
			}
			if (b[i]!=b[i-1]) {
				long long dif=b[i]-b[i-1];
				if (dif>d||dif<0) {
					flag=false;
					break;
				}
				a[i]=b[i];
				v.push_back({i,1});
			}
			if (c[i]!=c[i-1]) {
				long long dif=c[i-1]-c[i];
				if (dif>d||dif<0) {
					flag=false;
					break;
				}
				a[i]=c[i];
				v.push_back({i,2});
			}
		}
		if (!flag) {
			cout<<"NO"<<'\n';
			continue;
		}
		for (int i=0;i<(int)v.size()-1;i++) {
			if (v[i].second==v[i+1].second||v[i].second==0) {
				for (int j=v[i].first+1;j<v[i+1].first;j++) a[j]=a[v[i].first];
			} else if (v[i].second==1&&v[i+1].second==2) {
				for (int j=v[i].first+1;j<v[i+1].first;j++) a[j]=max(a[j-1]-d,c[v[i+1].first-1]);
			} else {
				for (int j=v[i].first+1;j<v[i+1].first;j++) a[j]=min(a[j-1]+d,b[v[i+1].first-1]);
			}
		}
		for (int i=v.back().first+1;i<=n;i++) a[i]=a[i-1];
		for (int i=2;i<=n;i++) {
			long long dif=abs(a[i]-a[i-1]);
			if (dif>d) {
				flag=false;
				break;
			}
		}
		if (!flag) cout<<"NO"<<'\n';
		else {
			cout<<"YES"<<'\n';
			for (int i=1;i<=n;i++) cout<<a[i]<<' ';
			cout<<'\n';
		}
	}
}