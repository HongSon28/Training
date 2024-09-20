#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
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
    	int res=0;
    	if (n%2==1) res++;
    	for (auto i:s) c[i-'a']++;
    	for (int i=0;i<26;i++) {
    		res=max(res,c[i]*2-n);
    		c[i]=0;
    	}
    	cout<<res<<'\n';
    }
}