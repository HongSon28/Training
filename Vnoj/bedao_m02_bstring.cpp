#include<bits/stdc++.h>
using namespace std;
string s;
int c0,n,res1,res2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>s;
	for (auto i:s) {
		if (i=='0') c0++;
	} 
	s=' '+s;
	for (int i=c0+1;i<=n;i++) res1+=(s[i]=='0');
	for (int i=1;i<=n-c0;i++) res2+=(s[i]=='0');
	cout<<min(res1,res2);
}