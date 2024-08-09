#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
pair<int,int>p[N+5];
set<pair<int,int>>s;
int d[N+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	for (int i=1;i<=n;i++) {
		s.insert({p[i].first-p[i].second,i});
		if (i%2==1) {
			pair<int,int>p=(*s.rbegin());
			d[p.second]=1;
			auto it=s.end();
			it--;
			s.erase(it);
		}
	}
	for (int i=1;i<=n;i++) 
		if (d[i]==0) res+=p[i].first;
		else res+=p[i].second;
	cout<<res;
}