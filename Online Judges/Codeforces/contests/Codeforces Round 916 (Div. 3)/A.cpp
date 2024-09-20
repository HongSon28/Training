#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int c[26];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>n>>s;
    	for (int i=0;i<26;i++) c[i]=i;
    	int res=0;
    	for (auto i:s) {
    		if (c[i-'A']==0) res++;
    		c[i-'A']--;
    	}
    	cout<<res<<'\n';
    }	
}