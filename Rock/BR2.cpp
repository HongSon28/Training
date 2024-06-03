#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
string s;
int n;
long long d[N+5][N+5],res,mod=1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	d[0][0]=1;
	for (int i=1;i<=N;i++) {
		d[i][0]=d[i-1][1];
		for (int j=1;j<=i;j++) d[i][j]=(d[i-1][j-1]+d[i-1][j+1])%mod;
	}
	int t;
	cin>>t;
	while (t--) {
		cin>>s;
		res=0;
		n=s.size();
		s=' '+s;
		int cur=0;
		for (int i=1;i<=n;i++) {
			if (s[i]=='(') cur++;
			else {
				res+=d[n-i][cur+1];
				res%=mod;
				cur--;
			}
		}
		cout<<(res+1)%mod<<'\n';
	}
}