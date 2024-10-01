#include<bits/stdc++.h>
using namespace std;
const int N=8,M=1e7;
int n,dest;
vector<int>v;
int a[N],b[N];
long long c[N][N];
int conv() {
	int ans=0;
	for (int i=1;i<=n;i++) ans=(ans*10)+b[i];
	return ans;
}
vector<int>cprs;
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
long long d[M+5],inf=1e18;
long long dijk() {
	for (int i=dest;i<=M;i++) d[i]=inf;
	int t=conv();
	d[t]=0;
	pq.push({t,0});
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[u]) continue;
		int pos=n,t=u;
		while (pos>0) {
			b[pos]=t%10;
			t/=10;
			pos--;
		}
		for (int i=1;i<n;i++) {
			for (int j=i+1;j<=n;j++) {
				swap(b[i],b[j]);
				int v=conv();
				//cout<<u<<' '<<v<<endl;
				if (d[u]+c[i][j]<d[v]) {
					d[v]=d[u]+c[i][j];
					pq.push({v,d[v]});
				}
				swap(b[i],b[j]);
			}
		}
	}
	return d[dest];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	int t;
	while (cin>>t) v.push_back(t);
	n=sqrt(v.size());
	for (int i=1;i<=n;i++) dest=dest*10+i;
	for (int i=1;i<=n;i++) a[i]=v[i-1];
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			int pos=i*n+j-1;
			c[i][j]=v[pos];
		}
	}
	for (int i=1;i<=n;i++) cprs.push_back(a[i]);
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=1;i<=n;i++) b[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
	cout<<dijk();
}