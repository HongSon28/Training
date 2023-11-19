#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>res[20],b;
int mx;
void rec(vector<int>v,int k) {
	if (v.size()==1) return;
	mx=max(mx,k);
	int mid=v.size()/2-1;
	vector<int>v1,v2;
	for (int i=mid;i>=0;i--) v1.push_back(v[i]);
	for (int i=mid+1;i<(int)v.size();i++) v2.push_back(v[i]);
	for (int i=v1.size()-1;i>=0;i--) res[k].push_back(v1[i]);
	rec(v1,k+1);
	rec(v2,k+1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int t,i=1;i<=n;i++) cin>>t;
	for (int t,i=1;i<=n;i++) {
		cin>>t;
		b.push_back(t);
	} 
	rec(b,1);
	cout<<mx<<'\n';
	for (int i=mx;i>=1;i--) {
		cout<<res[i].size()<<' ';
		for (auto t:res[i]) cout<<t<<' ';;
		cout<<'\n';
	}
}