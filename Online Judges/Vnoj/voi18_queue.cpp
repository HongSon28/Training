#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int t,n,m;
pair<int,int>p[N+5];
priority_queue<int,vector<int>,greater<int>>pq;
bool check(int k) {
	while (!pq.empty()) pq.pop();
	vector<pair<int,int>>v;
	for (int i=1;i<=k;i++) v.push_back(p[i]);
	sort(v.begin(),v.end());
	int j=0;
	for (int i=1;i<=m;i++) {
		while (v[j].first<=i&&j<(int)v.size()) {
			pq.push(v[j].second);
			j++;
		}
		if (pq.empty()) continue;
		if (pq.top()>=i) pq.pop();
		else return false;
	}
	return pq.empty();
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>m>>n;
    	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    	int res=1,lo=1,hi=n;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (check(mid)) {
    			lo=mid+1;
    			res=mid;
    		} else hi=mid-1;
    	}
    	cout<<res<<'\n';
    }	
}