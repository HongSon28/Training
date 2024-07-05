#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n,u,v,mod=1e9+7,a[22],d[N+5],res;
vector<int>adj[N+5];
void dfs(int s,int par){
    for(auto i:adj[s]){
        if(i==par) continue;
        d[i]=d[s]+1;
        dfs(i,s);
    }
}
void solve() {
	fill(d,d+n+1,-1);
    d[1]=0;
    dfs(1,1);
    int cur=0;
    int e1=0,mx=0;
    for(int i=2;i<=n;i++){
        if(a[i]==a[1] && mx<d[i]){
            mx=d[i];
            e1=i;
        }
    }
    fill(d,d+n+1,-1);
    d[e1]=0;
    dfs(e1,e1);
    for(int i=1;i<=n;i++){
        if(a[i]==a[e1]){
            cur=max(cur,d[i]);
        }
    }
    fill(d,d+n+1,-1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[1]) {
        	d[i]=0;
        	dfs(i,i);
        	for (int j=1;j<=n;j++) {
        		if (a[j]==a[i] && mx<d[j]) {
        			mx=d[j];
        			e1=j;
        		}
        	}
        	fill(d,d+n+1,-1);
		    d[e1]=0;
		    dfs(e1,e1);
		    for (int j=1;j<=n;j++) 
		    	if (a[i]==a[j]) cur=max(cur,d[j]);
        	break;
        }
    }
    res+=cur;
}
void rec(int k){
    for(int i=0;i<2;i++){
        a[k]=i;
        if(k==n){
        	solve();
        } else rec(k+1);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rec(1);
    cout<<res;
}