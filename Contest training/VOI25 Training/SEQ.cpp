#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,k;
int a[N+5];
vector<int>cprs;
multiset<int>s;
int cnt[N+5],res=1;
bool check(int l,int r) {
	if (cnt[a[r]]!=0) s.erase(s.lower_bound(cnt[a[r]]));
	cnt[a[r]]++;
	s.insert(cnt[a[r]]);
	int temp=*s.rbegin();
	s.erase(s.lower_bound(cnt[a[r]]));
	cnt[a[r]]--;
	if (cnt[a[r]]!=0) s.insert(cnt[a[r]]);
	return ((r-l+1)-temp<=k);
}
int main() {
	freopen("seq.inp","r",stdin);
	freopen("seq.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		cprs.push_back(a[i]);
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
	int r=1;
	cnt[a[1]]++;
	s.insert(1);
	for (int l=1;l<=n;l++) {
		while (r+1<=n&&check(l,r+1)) {
			r++;
			if (cnt[a[r]]!=0) s.erase(s.lower_bound(cnt[a[r]]));
			cnt[a[r]]++;
			s.insert(cnt[a[r]]);
		}
		res=max(res,r-l+1);
		s.erase(s.lower_bound(cnt[a[l]]));
		cnt[a[l]]--;
		if (a[l]!=0) s.insert(cnt[a[l]]);
	}
	cout<<res;
}