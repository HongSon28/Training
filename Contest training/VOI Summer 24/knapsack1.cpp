#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=40,M=2e6;
int n;
long long m;
pair<long long,long long>p[N+5];
long long res;
int ps,cnt;
pair<long long,long long>mp[M+5],mn[M+5];
void rec1(int k,long long W,long long V) {
	if (k==n+1) {
		mp[++cnt]={W,V};
		return;
	}
	if (W+p[k].first<=m) {
		rec1(k+1,W+p[k].first,V+p[k].second);
		rec1(k+1,W,V);
	} else {
		mp[++cnt]={W,V};
		return;
	}
}
long long get(long long W,long long V) {
	int lo=1,hi=ps,ans=0;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (mn[mid].first+W<=m) {
			ans=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	return V+mn[ans].second;
}
void rec2(int k,long long W,long long V) {
	//cout<<k<<' '<<W<<' '<<V<<endl;
	if (k==n/2+1) {
		res=max(res,get(W,V));
		return;
	}
	if (W+p[k].first<=m) {
		rec2(k+1,W+p[k].first,V+p[k].second);
		rec2(k+1,W,V);
	} else {
		res=max(res,get(W,V));
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    rec1(n/2+1,0,0);
    sort(mp+1,mp+1+cnt);
    for (int i=1;i<=cnt;i++) {
    	if (i==cnt||mp[i].first!=mp[i+1].first) mn[++ps]=mp[i];
    }
    for (int i=2;i<=ps;i++) mn[i].second=max(mn[i].second,mn[i-1].second);
    res=mn[ps].second;
    rec2(1,0,0);
    cout<<res;	
}