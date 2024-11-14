#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<long long,long long>p[N+5];
multiset<long long>s;
long long res,cur;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n);
	s.insert(p[1].second);
	cur=p[1].first;
	for (int i=2;i<=n;i++) {
		while (cur<p[i].first&&!s.empty()) {
			long long k=*s.begin();
			s.erase(s.begin());
			long long temp=min(k,p[i].first-cur);
			k-=temp,cur+=temp;
			if (k==0) res+=cur;
			else s.insert(k);
		}
		s.insert(p[i].second);
		cur=max(cur,p[i].first);
	}
	while (!s.empty()) {
		long long k=*s.begin();
		s.erase(s.begin());
		cur+=k;
		res+=cur;
	}
	cout<<res;
}