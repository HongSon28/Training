#include<bits/stdc++.h>
using namespace std;
const int N=1e5,SQ=316;
int n,m;
int a[N+5];
struct query{
	int l,r,id;
	bool operator < (const query &other) const {
		if (l/SQ!=other.l/SQ) return l/SQ<other.l/SQ;
		return r<other.r;
	}
} q[N+5];
int res[N+5];
int cnt[N+5],cur,l,r; 
void add(int x) {
	if (x>N) return;
	if (x==cnt[x]) cur--;
	cnt[x]++;
	if (x==cnt[x]) cur++;
} 
void del(int x) {
	if (x>N) return;
	if (x==cnt[x]) cur--;
	cnt[x]--;
	if (x==cnt[x]) cur++;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
    	cin>>q[i].l>>q[i].r;
    	q[i].id=i;
    }
    sort(q+1,q+1+m);
    add(a[1]);
    l=r=1;
    for (int i=1;i<=m;i++) {
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
    for (int i=1;i<=m;i++) cout<<res[i]<<'\n';
}