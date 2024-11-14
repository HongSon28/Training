#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long k;
int p[N+5];
bool used[N+5];
int res[N+5];
long long power(long long x,long long y,long long mod) {
	if (y==1) return x;
	long long ans=power(x,y/2,mod);
	ans=(ans*ans)%mod;
	if (y&1) ans=(ans*x)%mod;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>p[i];
	vector<int>cur;
	for (int i=1;i<=n;i++) {
		if (used[i]) continue;
		used[i]=true;
		cur.clear();
		cur.push_back(i);
		int t=p[i];
		while (t!=i) {
			used[t]=true;
			cur.push_back(t);
			t=p[t];
		}
		int m=cur.size();
		long long c=power(2,k,m)-1;
		if (c<0) c+=m;
		for (int i=0;i<m;i++) res[cur[i]]=cur[(i+c)%m];
	}
	for (int i=1;i<=n;i++) cout<<p[res[i]]<<' ';
}