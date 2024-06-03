#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=18;
int n,m;
int nxt[N+5][LG+5];
pair<int,int>mx[N+5];
pair<int,int>p[N+5];
bool check(int i,int t,int k) {
	for (int j=LG;j>=0;j--) {
		if (k>>j&1) {
			i=nxt[i][j];
		}
	}
	return p[i].second>=t;
}
int calc(int t,int i) {
	int lo=0,hi=m,ans=m+1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(i,t,mid)) {
			ans=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	//cout<<i<<' '<<ans<<endl;
	return ans+1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	int res=m+1;
	for (int i=1;i<=m;i++) {
		cin>>p[i].first>>p[i].second;
	}
	sort(p+1,p+1+m);
	for (int i=1;i<=m;i++) if (p[i].first>p[i].second) mx[0]=max(mx[0],{p[i].second,i});
	for (int i=1;i<=m;i++) mx[i]=max(mx[i-1],{p[i].second,i});
	for (int i=1;i<=m;i++) {
		int lo=1,hi=m,ans=0;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (p[mid].first<=p[i].second+1) {
				ans=mid;
				lo=mid+1;
			} else hi=mid-1;
		}
		nxt[i][0]=mx[ans].second;
		//cout<<i<<' '<<mx[ans].second<<endl;
	}
	for (int j=1;j<=LG;j++)
		for (int i=1;i<=m;i++)
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	for (int i=1;i<=m;i++) {
		if (p[i].first>p[i].second) res=min(res,calc(p[i].first-1,i));
		else if (p[i].first==1) res=min(res,calc(n,i));
	}
	cout<<m-res;
} 