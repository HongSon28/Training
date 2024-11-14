#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n,m,k;
bool del[N+5][N+5][N+5];
int cnt[N+5];
void dfs(int u,int v,int len) {
	if (u+len-1>n||v+len-1>m||u<1||v<1) return;
	if (del[u][v][len]) return;
	del[u][v][len]=true;
	cnt[len]--;
	dfs(u,v,len+1);
	dfs(u,v-1,len+1);
	dfs(u-1,v,len+1);
	dfs(u-1,v-1,len+1);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) 
    		for (int k=1;k<=min(n-i+1,m-j+1);k++) cnt[k]++;
    }
    cin>>k;
    int res=min(n,m);
    while (k--) {
    	int u,v;
    	cin>>u>>v;
    	dfs(u,v,1);
    	while (res>0&&cnt[res]==0) res--;
    	cout<<res*res<<'\n';
    }
}