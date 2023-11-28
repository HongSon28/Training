#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=100;
int n,k,a[N+5],res;
int c[M+5];
pair<int,int>p[M+5];
bool used[M+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		c[a[i]%k]++;
	}
	for (int i=0;i<=k;i++) {
		p[i].first=c[i];
		p[i].second=i;
	}
	sort(p+1,p+1+k,greater<pair<long long,long long>>());
	for (int i=0;i<=k;i++) {
		if (k%2==0&&p[i].second==k/2) {
			res+=min(1,p[i].first);
			continue;
		}
		if (p[i].second==0) {
			res+=min(1,p[i].first);
			continue;
		}
		if (!used[k-p[i].second]) {
			used[p[i].second]=true;
			res+=p[i].first;
		}
	}
	cout<<res;
}