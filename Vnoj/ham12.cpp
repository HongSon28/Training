#include<bits/stdc++.h>
using namespace std;
int m,n,k,res;
string s,t;
int calc(int pos) {
	int ans=0;
	for (int i=0;i<m;i++) ans+=(t[i]!=s[i+pos]);
	return ans; 
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>k>>s;
	s+=s;
	res=m;
	while (k--) {
		cin>>t;
		for (int i=0;i<n;i++) res=min(res,calc(i));
	}
	cout<<res;
}