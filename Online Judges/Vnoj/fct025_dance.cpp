#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
int c[N+5];
vector<int>v;
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		int t;
		cin>>t;
		if (t>0) c[t]++;
		else v.push_back(-t);
	}
	for (int i=1;i<=N;i++) c[i]+=c[i-1];
	for (auto x:v) {
		res+=c[x+k]-c[x-1];
	}
	cout<<res;
}