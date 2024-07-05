#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
pair<long long,long long>p[N+5];
double res;
bool vis[N+5];
queue<int>q;
double dist(int u,int v) {
	return sqrt((p[u].first-p[v].first)*(p[u].first-p[v].first)+(p[u].second-p[v].second)*(p[u].second-p[v].second));
}
bool check(double k) {
	for (int i=1;i<=n;i++) vis[i]=false;
	while (!q.empty()) q.pop();
	vis[1]=true;
	q.push(1);
	while (!q.empty()) {
		int u=q.front();
		//cout<<k<<' '<<u<<endl;
		q.pop();
		for (int v=1;v<=n;v++) {
			if (vis[v]) continue;
			if (dist(u,v)>2*k) continue;
			//cout<<k<<' '<<u<<' '<<v<<' '<<dist(u,v)<<endl;
			vis[v]=true;
			q.push(v);
		}
	}
	for (int i=1;i<=n;i++) {
		if (!vis[i]) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	double l=0,r=5e8;
	while (r-l>1e-8) {
		double mid=(l+r)/2;
		//cout<<fixed<<l<<' '<<r<<' '<<mid<<' '<<check(mid)<<endl;
		if (check(mid)) {
			res=mid;
			r=mid;
		} else l=mid;
	} 
	cout<<to_string(res);
}