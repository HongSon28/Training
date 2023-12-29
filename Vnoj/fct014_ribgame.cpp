#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,sum,res=INT_MAX;
int c[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int l,r,s;
		cin>>l>>r>>s;
		c[l]+=s;
		c[r+1]-=s;
		sum+=s;
	}
	for (int i=1;i<=m;i++) {
		c[i]+=c[i-1];
		res=min(res,c[i]);
	}
	cout<<sum-res;
}