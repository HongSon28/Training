#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
pair<int,int>p[N+5];
vector<int>cprs;
int cp[N+5];
int main() {
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>p[i].first>>p[i].second;
		cprs.push_back(p[i].first);
		cprs.push_back(p[i].second);
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=1;i<=n;i++) {
		p[i].first=lower_bound(cprs.begin(),cprs.end(),p[i].first)-cprs.begin()+1;
		p[i].second=lower_bound(cprs.begin(),cprs.end(),p[i].second)-cprs.begin()+1;
	}
}