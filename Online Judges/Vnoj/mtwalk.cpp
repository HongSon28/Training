#include<bits/stdc++.h>
using namespace std;
int n,res;
int a[101][101];
bool vis[101][101];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool bfs(int mn,int mx) {
	queue<pair<int,int>>q;
	memset(vis,false,sizeof(vis));
	vis[1][1]=true;
	q.push({1,1});
	while (!q.empty()) {
		pair<int,int>t=q.front();
		if (t.first==n&&t.second==n) return true;
		q.pop();
		for (int i=0;i<4;i++) {
			int x=t.first+dx[i];
			int y=t.second+dy[i];
			if (x>=1&&y>=1&&x<=n&&y<=n&&a[x][y]>=mn&&a[x][y]<=mx&&!vis[x][y]) {
				vis[x][y]=true;
				q.push({x,y});
			}
		}
	}
	return false;
}
bool check(int m) {
	for (int i=a[1][1]-m;i<=a[1][1];i++) if (bfs(i,i+m)) return true;
	return false;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    int lo=0,hi=200;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            hi=mid-1;
            res=mid;
        } else {
            lo=mid+1;
        }
    }
    cout<<res;
}
