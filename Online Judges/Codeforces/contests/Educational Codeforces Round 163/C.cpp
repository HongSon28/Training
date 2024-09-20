#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
char c[3][N+5];
bool p[3][N+5];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void solve() {
	memset(p,false,sizeof(p));
	queue<pair<int,int>>q;
	p[1][1]=true;
	q.push({1,1});
	while (!q.empty()) {
		int u=q.front().first,v=q.front().second;
		q.pop();
		for (int i=0;i<4;i++) {
			int x=u+dx[i],y=v+dy[i];
			if (x<1||x>2||y<1||y>n) continue;
			if (c[x][y]=='<') y--;
			else y++;
			if (x>=1&&x<=2&&y>=1&&y<=n&&!p[x][y]) {
				p[x][y]=true;
				q.push({x,y});
			} 
		}
	}
	if (p[2][n]) cout<<"YES";
	else cout<<"NO";
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>c[1][i];
    	for (int i=1;i<=n;i++) cin>>c[2][i];
    	solve();
    	cout<<'\n';
    }
}