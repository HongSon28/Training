#include<bits/stdc++.h>
using namespace std;
const int N=2e5,M=1e6,SZ=447;
int n,t;
int a[N+5];
long long cnt[M+5],res[N+5],cur;
struct Query{
	int l,r,id;
	bool operator < (const Query &other) const {
		if (l/SZ!=other.l/SZ) return l/SZ<other.l/SZ;
		return r<other.r;
	}
} q[N+5];
void add(int x) {
	cur+=cnt[x]*2*x+x;
	cnt[x]++;
}
void del(int x) {
	cur-=cnt[x]*2*x-x;
	cnt[x]--;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>t;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=t;i++) {
		q[i].id=i;
		cin>>q[i].l>>q[i].r;
	}
	sort(q+1,q+1+t);
	int l=1,r=1;
	cnt[a[1]]++;
	cur=a[1];
	for (int i=1;i<=t;i++) {
		while (l<q[i].l) {
			del(a[l]);
			l++;
		}
		while (l>q[i].l) {
			l--;
			add(a[l]);
		}
		while (r<q[i].r) {
			r++;
			add(a[r]);
		}
		while (r>q[i].r) {
			del(a[r]);
			r--;	
		}
		res[q[i].id]=cur;
	}
	for (int i=1;i<=t;i++) cout<<res[i]<<'\n';
}