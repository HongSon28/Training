#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
long long k;
long long a[N+5],sum[N+5];
int l[N+5],r[N+5];
vector<pair<long long,int>>v;
int res;
int bit[N+5];
void update(int idx) {
	while (idx<=n) {
		bit[idx]++;
		idx+=(idx&(-idx));
	}
}
int get(int idx) {
	int ans=0;
	while (idx>0) {
		ans+=bit[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int cur=1;
	for (int i=1;i<=n;i++) {
		while (cur<=i&&sum[i]-sum[cur-1]>k) cur++;
		l[i]=cur;
		if (cur>i) l[i]=-1;
	}
	cur=0;
	for (int i=1;i<=n;i++) {
		cur=max(cur,i-1);
		while (cur<n&&sum[cur+1]-sum[i-1]<=k) cur++;
		r[i]=cur;
		if (cur<i) r[i]=-1;
		else v.push_back({r[i]-i*2,i});
	}
	sort(v.rbegin(),v.rend());
	cur=0;
	for (int i=2;i<n;i++) {
		while (cur<(int)v.size()&&v[cur].first>=-i-1) {
			update(v[cur].second);
			cur++;
		}
		if (l[i-1]==-1||r[i]==-1) continue;
		int mx=i+min(i-l[i-1],r[i]-i+1),lo=i+1,hi=mx,ans=i;
		//cout<<i<<' '<<lo<<' '<<hi<<' ';
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (get(mx)-get(mid-1)>0) {
				ans=mid;
				lo=mid+1;
			} else hi=mid-1;
		}
		//cout<<ans<<endl;
		res=max(res,ans-i);
	}
	cout<<res;
}