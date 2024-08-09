#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n,k;
vector<pair<int,int>>pos[N*N+5];
int d[N+5][N+5];
int inf=1e9,res=inf;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			d[i][j]=inf;
			int temp;
			cin>>temp;
			pos[temp].push_back({i,j});
		}
	}
	for (auto [x,y]:pos[1]) d[x][y]=0;
	for (int i=2;i<=k;i++) {
		for (auto [x,y]:pos[i]) {
			for (auto [i,j]:pos[i-1]) d[x][y]=min(d[x][y],d[i][j]+abs(x-i)+abs(y-j));
		}
	}
	for (auto [x,y]:pos[k]) res=min(res,d[x][y]);
	if (res==inf) cout<<-1;
	else cout<<res;
}