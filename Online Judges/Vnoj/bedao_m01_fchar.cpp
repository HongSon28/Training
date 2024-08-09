#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int m,n,c[5][N+5],res=INT_MAX;
string s;
bool check(int l,int r) {
	for (int j=0;j<5;j++) {
		int temp=c[j][r]-c[j][l-1];
		if (temp<m) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s>>m;
	n=s.size();
	s=' '+s;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<5;j++) c[j][i]=c[j][i-1];
		if (s[i]<='e') c[s[i]-'a'][i]++; 
	}
	for (int i=1;i<=n;i++) {
		if (c[0][n]-c[0][i-1]<m||c[1][n]-c[1][i-1]<m||c[2][n]-c[2][i-1]<m||c[3][n]-c[3][i-1]<m||c[4][n]-c[4][i-1]<m) break;
		int lo=i,hi=n;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (check(i,mid)) {
				res=min(res,mid-i+1);
				hi=mid-1;
			} else lo=mid+1;
		}
	}
	if (res==INT_MAX) cout<<-1;
	else cout<<res;
}
