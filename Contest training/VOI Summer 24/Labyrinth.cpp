#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m;
char c[N+5][N+5];
bool vis[N+5][N+5];
pair<int,int>trace[N+5][N+5];
queue<pair<int,int>>q;
int px,py;
bool check(int x,int y) {
	return (x>=1&&y>=1&&x<=n&&y<=m&&!vis[x][y]&&c[x][y]!='#');
}
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		cin>>c[i][j];
    		if (c[i][j]=='A') {
    			q.push({i,j});
    			vis[i][j]=true;
    		} else if (c[i][j]=='B') {
    			px=i;
    			py=j;
    		}
    	}
    }
    while (!q.empty()) {
    	int u=q.front().first,v=q.front().second;
    	q.pop();
    	if (c[u][v]=='B') break;
    	for (int i=0;i<4;i++) {
    		int x=u+dx[i],y=v+dy[i];
    		if (check(x,y)) {
    			q.push({x,y});
    			vis[x][y]=true;
    			trace[x][y]={u,v};
    		}
    	}
    }
    if (!vis[px][py]) {
    	cout<<"NO";
    	return 0;
    }
    string res;
    cout<<"YES"<<'\n';
    while (c[px][py]!='A') {
    	pair<int,int>t=trace[px][py];
    	if (t.first+1==px) res+="D";
    	else if (t.first-1==px) res+="U";
    	else if (t.second+1==py) res+="R";
    	else res+="L";
    	px=t.first,py=t.second;
    }
    reverse(res.begin(),res.end());
    cout<<res.size()<<'\n'<<res;
}