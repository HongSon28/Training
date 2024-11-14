#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
pair<long long,long long>p[N+5];
long long mod=1e9+7,res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n);
	for (int i=1;i<=n;i++) {
		long long l=-1,r=-1;
		for (int j=i+1;j<=n;j++) {
			if (l==-1||r==-1) {
				if (p[j].second<p[i].second) {
					if (l==-1||l<p[j].second+1) l=p[j].second+1;
				} else if (p[j].second>p[i].second) {
					if (r==-1||r>p[j].second-1) r=p[j].second-1;
				}
			} else {
				if (p[j].second>=l&&p[j].second<=r) {
					res+=(p[j].first-1-p[i].first-1+1)*(r-l+1)%mod;
					res%=mod;
					//cout<<p[i].first<<' '<<p[j].first<<' '<<l<<' '<<r<<endl;
				}
				if (p[j].second<p[i].second) {
					if (l==-1||l<p[j].second+1) l=p[j].second+1;
				} else if (p[j].second>p[i].second) {
					if (r==-1||r>p[j].second-1) r=p[j].second-1;
				}
			} 
			//cout<<p[j].first<<' '<<p[j].second<<' '<<l<<' '<<r<<endl;
		}
	}
	cout<<res;
}