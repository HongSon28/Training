#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>a;
vector<vector<char>>c;
vector<vector<int>>b;
queue<pair<int,int>>q;
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={-1,0,1,-1,1,1,0,-1};
int res;
bool check(int k) {
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (a[i][j]>=k+1) {
				q.push({i,j});
				b[i][j]=0;
			} else b[i][j]=-1;
		}
	}
	while (!q.empty()) {
    	int u=q.front().first,v=q.front().second;
    	q.pop();
    	if (b[u][v]==k) continue;
    	for (int i=0;i<8;i++) {
    		int x=u+dx[i],y=v+dy[i];
    		if (x>=1&&y>=1&&x<=n&&y<=m&&b[x][y]==-1&&c[x][y]=='X') {
    			b[x][y]=b[u][v]+1;
    			q.push({x,y});
    		}
    	}
    }
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (c[i][j]=='X'&&b[i][j]==-1) return false;
    	}
    }
    return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    a.resize(n+2),b.resize(n+2),c.resize(n+2);
    for (int i=1;i<=n;i++) {
    	a[i].resize(m+2),b[i].resize(m+2),c[i].resize(m+2);
    	for (int j=1;j<=m;j++){
    		cin>>c[i][j];
    		if (c[i][j]=='.') {
    			a[i][j]=0;
    			q.push({i,j});
    		} else a[i][j]=-1;
    	}
    }
    a[0].resize(m+2),c[0].resize(m+2);
    a[n+1].resize(m+2),c[n+1].resize(m+2);
    for (int i=1;i<=m;i++) {
    	a[0][i]=0;
    	q.push({0,i});
    	a[n+1][i]=0;
    	q.push({n+1,i});
    }
    for (int i=1;i<=n;i++) {
    	a[i][0]=0;
    	q.push({i,0});
    	a[i][m+1]=0;
    	q.push({i,m+1});
    }
    while (!q.empty()) {
    	int u=q.front().first,v=q.front().second;
    	q.pop();
    	for (int i=0;i<8;i++) {
    		int x=u+dx[i],y=v+dy[i];
    		if (x>=1&&y>=1&&x<=n&&y<=m&&a[x][y]==-1&&c[x][y]=='X') {
    			a[x][y]=a[u][v]+1;
    			q.push({x,y});
    		}
    	}
    }
    int lo=0,hi=n*m;
    while (lo<=hi) {
    	int mid=(lo+hi)/2;
    	if (check(mid)) {
    		res=mid;
    		lo=mid+1;
    	} else hi=mid-1;
    }
    cout<<res<<'\n';
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (a[i][j]>=res+1&&c[i][j]=='X') cout<<'X';
    		else cout<<'.';
    	}
    	cout<<'\n';
    }
}