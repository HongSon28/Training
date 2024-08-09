#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
long long a[N+5],c[N+5],d[N+5],cnt[N+5];
vector<long long>v[N+5];
void seive() {
	for (int i=1;i<=N;i++) {
		for (int j=i;j<=N;j+=i) d[j]=i;
	}
	for (int i=1;i<=N;i++) v[d[i]].push_back(i);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	seive();
	cin>>t;
	while (t--) {
		long long res=0;
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			c[a[i]]++;
		}
		for (int i=1;i<=N;i++) cnt[i]=cnt[i-1]+c[i];
		for (int i=1;i<=N;i++) {
			for (int j=0;j<(int)v[i].size();j++) {
				cout<<i<<' '<<v[i][j]<<' '<<c[v[i][j]]<<'\n';
				res+=i*c[v[i][j]]*(c[v[i][j]]-1)*(cnt[N]-cnt[v[i][j]])/2;
				for (int k=j+1;k<(int)v[j].size();k++) res+=i*c[v[i][j]]*c[v[i][k]]*(cnt[N]-cnt[v[i][k]]);
			}
		}
		for (int i=1;i<=n;i++) c[a[i]]--;
		cout<<res<<'\n';
	}
}