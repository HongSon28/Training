#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,q;
int a[N+5];
int ex[N+5];
int cnt[N+5],d[N+5];
vector<int>p[N+5];
long long res;
void update(int val,int sign) {
	for (int mask=0;mask<(1<<p[val].size());mask++) {
		if (!mask) d[mask]=1;
		else d[mask]=d[mask&(mask-1)]*p[val][__builtin_ctz(mask)];
		if (sign<0) cnt[d[mask]]--;
		if (__builtin_popcount(mask)%2==1) res-=cnt[d[mask]]*sign;
		else res+=cnt[d[mask]]*sign;
		if (sign>0) cnt[d[mask]]++;
	}
}
void seive() {
	for (int i=2;i<=N;i++) {
		if (p[i].empty()) {
			for (int j=i;j<=N;j+=i) p[j].emplace_back(i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	ex[i]=1;
    }
    while (q--) {
    	int val;
    	cin>>val;
    	update(a[val],ex[val]);
    	ex[val]=-ex[val];
    	cout<<res<<'\n';
    }
}