#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m;
char c[N+5][N+5];
long long sum,res;
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,0,-1,1,-1,1,0,-1};
long long cnt(int x,int y) {
	long long ans=0;
	for (int i=0;i<8;i++) {
		ans+=(c[x+dx[i]][y+dy[i]]=='#');
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) 
    	for (int j=1;j<=m;j++)
    		cin>>c[i][j];
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (c[i][j]=='.') res=max(res,cnt(i,j));
    		else sum+=cnt(i,j);
    	}
    }
    cout<<res+sum/2;
}