#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int n;
int x[N+5],a[N+5],b[N+5];
pair<int,int>p[N+5];
int res[N+5],c[N+5];
int cnt[N+5];
bool check(int l,int r) {
	r--;
	return (cnt[r]-cnt[l-1]==0);
}
void solve() {
	 for (int i=1;i<n;i++) cnt[i]=cnt[i-1]+(p[i].first!=p[i+1].first);
	 for (int i=1;i<=n;i++) {
	 	int ans=i,lo=i+1,hi=n;
	 	while (lo<=hi) {
	 		int mid=(lo+hi)/2;
	 		if (check(i,mid)) {
	 			ans=mid;
	 			lo=mid+1;
	 		} else hi=mid-1;
	 	}
	 	int col=p[ans+1].second;
	 	while (ans<n&&(p[ans+1].second==col||p[ans+1].first==p[i].first)) ans++;
	 	if (res[i]<ans) {
	 		res[i]=ans;
	 		c[i]=1;
	 	} else if (res[i]==ans) c[i]++;
	 }
}
int main() {
	freopen("ROADSIGNS.INP","r",stdin);
	freopen("ROADSIGNS.ANS","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>x[i]>>a[i]>>b[i];
		p[i]={x[i]-a[i],x[i]+b[i]};
	}
	solve();
	for (int i=1;i<=n;i++) swap(p[i].first,p[i].second);
	solve();
	int mx=0,cnt=0;
	for (int i=1;i<=n;i++) {
		int cur=res[i]-i+1;
		if (cur>mx) {
			mx=cur;
			cnt=c[i];
		} else if (mx==cur) cnt+=c[i];
		//if (cur==3) cout<<i<<' '<<res[i]<<' '<<c[i]<<endl;
	}
	cout<<mx<<' '<<cnt;
}
