#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m,res;
string s[N+5],t[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>s[i];
	for (int i=1;i<=n;i++) cin>>t[i];
	for (int i=0;i<m;i++) {
		int mask1=0,mask2=0;
		for (int j=1;j<=n;j++) {
			if (s[j][i]=='A') mask1|=1;
			else if (s[j][i]=='T') mask1|=2;
			else if (s[j][i]=='G') mask1|=4;
			else mask1|=8;
		} 
		for (int j=1;j<=n;j++) {
			if (t[j][i]=='A') mask2|=1;
			else if (t[j][i]=='T') mask2|=2;
			else if (t[j][i]=='G') mask2|=4;
			else mask2|=8;
		} 
		res+=((mask1&mask2)==0);
	}
	cout<<res;
}