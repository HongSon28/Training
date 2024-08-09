#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,q;
vector<vector<pair<int,int>>>query(N+5);
int a[N+5];
map<int,int>last;
int res[N+5];
int bit[N+5];
void update(int x,int val) {
	int idx=x;
	while (idx<=n) {
		bit[idx]^=val;
		idx+=idx&(-idx);
	}
}
int get(int x) {
	int idx=x;
	int ans=0;
	while (idx>0) {
		ans^=bit[idx];
		idx-=idx&(-idx);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=q;i++) {
    	int l,r;
    	cin>>l>>r;
    	query[r].push_back({l,i});
    }
    for (int i=1;i<=n;i++) {
    	if (last.find(a[i])!=last.end()) update(last[a[i]],a[i]);
    	last[a[i]]=i;
    	update(i,a[i]);
    	for (auto [l,id]:query[i]) res[id]=(get(l-1)^get(i));
    }
    for (int i=1;i<=q;i++) cout<<res[i]<<' ';
}