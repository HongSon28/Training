#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n,m;
char c[N+5][N+5];
int l[N+5][N+5],r[N+5][N+5],d[N+5][N+5];
struct Fenwick{
	int bit[N+5];
	void update(int idx) {
		while (idx<=n) {
			bit[idx]++;
			idx+=(idx&(-idx));
		}
	}
	int getpre(int idx) {
		int ans=0;
		while (idx>0) {
			ans+=bit[idx];
			idx-=(idx&(-idx));
		}
		return ans;
	}
	long long get(int l,int r) {
		return getpre(r)-getpre(l-1);
	}
	
} tree[N*2+5];
long long res;
long long prep(int x,int y) {
	int cur=0;
	while (x>=1&&y<=m) {
		if (c[x][y]=='z') cur++;
		else cur=0;
		d[x][y]=cur;
		x--;
		y++;
	}
}
vector<pair<int,int>>v[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	int cur=0;
    	for (int j=1;j<=m;j++) {
    		cin>>c[i][j];
    		if (c[i][j]=='z') cur++;
    		else cur=0;
    		l[i][j]=cur;
    	}
    	cur=0;
    	for (int j=m;j>=1;j--) {
    		if (c[i][j]=='z') cur++;
    		else cur=0;
    		r[i][j]=cur;
    	}
    }
    for (int j=1;j<=m;j++) prep(n,j);
    for (int i=1;i<n;i++) prep(i,1);
    for (int i=1;i<=n;i++) 
    	for (int j=1;j<=m;j++) v[j+r[i][j]-1].push_back({i,j});
    for (int j=m;j>=1;j--) {
    	for (auto [x,y]:v[j]) tree[x+y].update(x);
    	for (int i=1;i<=n;i++) {
    		if (c[i][j]!='z') continue;
    		int mn=min(l[i][j],d[i][j]);
    		res+=tree[i+j].get(i,min(n,i+mn-1));
    	}
    }
    cout<<res;
}