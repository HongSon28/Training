#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int n,m,res=-1;
char c[N+5][N+5];
vector<string>v;
int main() {
	freopen("ROWCUT.INP","r",stdin);
	freopen("ROWCUT.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>c[i][j];
	for (int j=1;j<=m;j++) {
		string temp;
		for (int i=1;i<=n;i++) temp+=c[i][j];
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	for (int j=1;j<m;j++) {
		for (int i=0;i<n;i++) {
			if (v[j][i]!=v[j-1][i]) break;
			res=max(res,i+1);
		}
	}
	cout<<n-res-1;
}