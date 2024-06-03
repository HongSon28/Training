#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int a[N+5][N+5];
int res,lo=1e9,hi; 
set<int>s[N+5];
struct dat{
	int val,pos;
	bool operator < (const dat &other) const {
		if (val!=other.val) return val<other.val;
		return pos<other.pos;
	}
};
set<dat>pq;
bool used[N+5];
bool check(int k) {
	pq.clear();
	for (int i=1;i<=n;i++) {
		s[i].clear();
		used[i]=false;
		for (int j=1;j<=n;j++) {
			if (a[i][j]>=k) s[i].insert(j);
		}
		pq.insert({s[i].size(),i});
	}
	while (!pq.empty()) {
		dat temp=*pq.begin();
		pq.erase(pq.begin());
		if (temp.val==0) return false;
		int pos=temp.pos;
		int j=*s[pos].begin();
		used[pos]=true;
		//cout<<pos<<' '<<j<<endl;
		for (int i=1;i<=n;i++) {
			if (used[i]) continue;
			if (!s[i].count(j)) continue;
			pq.erase(pq.find({s[i].size(),i}));
			s[i].erase(s[i].find(j));
			pq.insert({s[i].size(),i});
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			cin>>a[i][j];
			lo=min(lo,a[i][j]);
			hi=max(hi,a[i][j]);
		}
	}
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	cout<<res;
}