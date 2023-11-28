#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,k;
int s[N+5],t[N+5],r[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for (int i=1;i<=k;i++) cin>>s[i]>>t[i]>>r[i];
	for (int i=1;i<=k;i++) {
		int cur=0,res=0,page=n;
		while (page>0) {
			if (cur==t[i]) {
				res+=r[i];
				cur=0;
			}
			cur++;
			page-=s[i];
			res++;
		}
		cout<<res<<'\n';
	}
}