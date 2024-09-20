#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int t,n;
string s;
vector<vector<int>>v;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>s;
    	n=s.size();
    	s=' '+s;
    	v.clear();
    	v.resize(n+1);
    	int res=0;
    	for (int i=1;i<=n;i++)
    		for (int j=i+1;j<=n;j++) 
    			if (s[i]==s[j]||s[i]=='?'||s[j]=='?') v[j-i].push_back(i);
    	for (int len=2;len<=n;len+=2) {
    		if (v[len/2].empty()) continue;
    		sort(v[len/2].begin(),v[len/2].end());
    		int cur=1;
    		int mx=0;
    		for (int i=1;i<v[len/2].size();i++) {
    			//cout<<len/2<<' '<<v[len/2][i]<<' '<<v[len/2][i-1]<<'\n';
    			if (v[len/2][i]==v[len/2][i-1]+1) cur++;
    			else {
    				mx=max(mx,cur);
    				cur=1;
    			}
    		}
    		mx=max(mx,cur);
    		if (mx>=len/2) res=max(res,len);
    	}
    	cout<<res<<'\n';
    }
}