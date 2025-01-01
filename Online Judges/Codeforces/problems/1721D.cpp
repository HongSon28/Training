#include<bits/stdc++.h>
using namespace std;
int t,n;
int solve(int k,vector<vector<int>>a,vector<vector<int>>b) {
	if (k==-1) return 0;
	for (int i=0;i<(int)a.size();i++) {
		int c=0;
		for (auto x:a[i]) if (x>>k&1) c++;
		for (auto x:b[i]) if (!(x>>k&1)) c--;
		if (c!=0) return solve(k-1,a,b);
	}
	vector<vector<int>>ca,cb;
	for (int i=0;i<(int)a.size();i++) {
		vector<int>a0,a1,b0,b1;
		for (auto x:a[i]) {
			if (x>>k&1) a1.push_back(x);
			else a0.push_back(x);
		}
		for (auto x:b[i]) {
			if (x>>k&1) b1.push_back(x);
			else b0.push_back(x);
		}
		if (!a1.empty()) {
			ca.push_back(a1);
			cb.push_back(b0);
		}
		if (!a0.empty()) {
			ca.push_back(a0);
			cb.push_back(b1);
		}
	}
	/*
	cout<<k<<endl;
	for (int i=0;i<(int)ca.size();i++) {
		for (auto x:ca[i]) cout<<x<<' ';
		cout<<endl;
		for (auto x:cb[i]) cout<<x<<' ';
		cout<<endl;
	}
	cout<<endl;*/
	return solve(k-1,ca,cb)+(1<<k);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
		vector<vector<int>>a,b;
		a.resize(1),b.resize(1);
		cin>>n;
		for (int i=0;i<n;i++) {
			int c;
			cin>>c;
			a[0].push_back(c);
		}
		for (int i=0;i<n;i++) {
			int c;
			cin>>c;
			b[0].push_back(c);
		}
		cout<<solve(30,a,b)<<'\n';
	}
}
