#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
bool vis[N+5][N+5][4];
bool block[N+5][N+5];
int m,n,x,y,u,v;
struct dat{
	int x,y,d;
};
queue<dat>q;
dat trace[N+5][N+5][4];
int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};
bool check(int x,int y,int d) {
	if (vis[x][y][d]||block[x][y]) return false;
	return (x>=0&&y>=0&&x<=m&&y<=n);
}
vector<int>res;
void tr(int tx,int ty,int d) {
	//cout<<tx<<' '<<ty<<' '<<d<<endl;
	if (tx==x&&ty==y) {
		reverse(res.begin(),res.end());
		for (auto i:res) {
			if (i==0) cout<<"E";
			else if (i==1) cout<<"N";
			else if (i==2) cout<<"S";
			else cout<<"W";
		}
		return;
	}
	auto [tu,tv,td]=trace[tx][ty][d];
	for (int i=0;i<4;i++) {
		if (tu+dx[i]==tx&&tv+dy[i]==ty) res.push_back(i);
	}
	tr(tu,tv,td);
}
int main() {
	freopen("SPY.INP","r",stdin);
	freopen("SPY.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>m>>n>>x>>y>>u>>v;
    int tx,ty;
    while (cin>>tx>>ty) {
    	block[tx][ty]=true;
    }
    vis[x][y][0]=vis[x][y][1]=vis[x][y][2]=vis[x][y][3]=true;
	q.push({x,y,3});
	q.push({x,y,2});
	q.push({x,y,1});
	q.push({x,y,0});
	while (!q.empty()) {
		auto [uu,vv,d] = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			if (i==d) continue;
			if (check(uu+dx[i],vv+dy[i],i)) {
				q.push({uu+dx[i],vv+dy[i],i});
				vis[uu+dx[i]][vv+dy[i]][i]=true;
				trace[uu+dx[i]][vv+dy[i]][i]={uu,vv,d};
				//cout<<uu<<' '<<vv<<' '<<d<<' '<<uu+dx[i]<<' '<<vv+dy[i]<<' '<<i<<endl;
				if (uu+dx[i]==u&&vv+dy[i]==v) {
					tr(u,v,i);
					return 0;
				}
			}
		}
	}
	
}