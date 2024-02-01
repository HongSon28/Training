#include<bits/stdc++.h>
using namespace std;
int n,d;
vector<int>v;
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>d;
	for (int t,i=1;i<=n;i++) {
		cin>>t;
		if (t) v.push_back(i);
	}
	for (int i=1;i<(int)v.size();i++) {
		while (v[i]-v[i-1]>d) {
			v[i-1]+=d;
			res++;
		}
	}
	cout<<res;
}