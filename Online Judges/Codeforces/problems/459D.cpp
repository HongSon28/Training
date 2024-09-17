#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int cnt[N+5];
vector<int>cprs;
int l[N+5],r[N+5];
int bit[N+5];
long long res;
void update(int idx) {
	while (idx<=n) {
		bit[idx]++;
		idx+=idx&(-idx);
	}
}
int get(int idx) {
	int ans=0;
	while (idx>0) {
		ans+=bit[idx];
		idx-=idx&(-idx);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		cprs.push_back(a[i]);
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
	for (int i=1;i<=n;i++) {
		cnt[a[i]]++;
		l[i]=cnt[a[i]];
		//cout<<l[i]<<' ';
	}
	memset(cnt,0,sizeof(cnt));
	for (int i=n;i>=1;i--) {
		cnt[a[i]]++;
		r[i]=cnt[a[i]];
		//cout<<r[i]<<' ';
		res+=get(l[i]-1);
		update(r[i]);
	}
	cout<<res;
}