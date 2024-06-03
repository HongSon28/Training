#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,u,v,par[N+5];
vector<int>adj[N+5];
bool vis[N+5];
queue<int>q;
bool bfs(){
	for (int i=1;i<=n;i++) {
		if (vis[i]) continue;
	    q.push(i);
	    vis[i]=true;
	    par[i]=1;
	    while(!q.empty()){
	        int f=q.front();
	        q.pop();
	        for(auto i:adj[f]){
	            if (vis[i]) {
	            	if (par[i]!=par[f]) continue;
	            	else return false;
	            } else {
	            	vis[i]=true;
	            	par[i]=3-par[f];
	            	q.push(i);
	            }
	        }
	    }
    }
    return true;
}
int main(){
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(bfs()) cout<<"YES";
    else cout<<"NO";
}
