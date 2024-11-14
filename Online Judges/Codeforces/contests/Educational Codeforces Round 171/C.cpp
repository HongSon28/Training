#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>s;
		s=' '+s;
		long long res=(long long)n*(n+1)/2;
		int cnt=0;
		s[1]='0';
		queue<int>q;
		for (int i=n;i>=1;i--) {
			if (s[i]=='1') q.push(i);
			else {
				if (!q.empty()) {
					res-=q.front();
					q.pop();
				}
			} 
		}
		if (!q.empty()) {
			int t=q.size()/2;
			while (t--) {
				res-=q.front();
				q.pop();
			}
		}
		cout<<res<<'\n';
	}
}