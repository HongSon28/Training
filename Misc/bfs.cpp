#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int m,n,u,v,cnt,d[N+5];
vector<int>vt[N+5];
void bfs(){
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
		for (auto v:vt[u]) {
			if (d[v]!=-1) continue;
			d[v]=d[u]+1;
			q.push(v);
		}
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        cin>>u>>v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    fill(d,d+1+n,-1);
    d[1]=0;
    bfs();
    for(int i=2;i<=n;i++) cout<<d[i]<<' ';
}