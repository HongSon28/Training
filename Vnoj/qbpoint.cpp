#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int n;
long long res;
int a[N+5],b[N+5];
bool comp(pair<int,int>x,pair<int,int>y) {
	return x.second*y.first<x.first*y.second;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for (int i=1;i<=n;i++) {
		vector<pair<int,int>>v;
		for (int j=1;j<=n;j++) {
			int x=a[j]-a[i],y=b[j]-b[i];
			if (y<0||(y==0&&x<=0)) continue;
			v.push_back({x,y});
		}
		if (v.empty()) continue;
		sort(v.begin(),v.end(),comp);
		long long cur=1;
		for (int i=1;i<(int)v.size();i++) {
			if (!comp(v[i],v[i-1])&&!comp(v[i-1],v[i])) res+=cur++;
			else cur=1;
		}
	}
	cout<<res;
}