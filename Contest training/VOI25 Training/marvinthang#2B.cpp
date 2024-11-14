#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=5e5;
int n;
vector<pair<int,long long>>adj[N+5];
int a[N+5];
int d[N+5];
int fai[N+5];
int rmq[N*2+5][22];
long long sum[N+5];
int cur;
vector<int>euler;
void dfs(int u,int par) {
	d[u]=d[par]+1;
	cur++;
	if (fai[u]==0) fai[u]=cur;
	euler.push_back(u);
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		sum[v]=sum[u]+w;
		dfs(v,u);
		euler.push_back(u);
		cur++;
	}
}
void prep() {
	int m=euler.size()-1;
	for (int i=1;i<=m;i++) rmq[i][0]=euler[i];
	for (int j=1;(1<<j)<=m;j++) {
		for (int i=1;i+(1<<j)-1<=m;i++) {
			if (d[rmq[i][j-1]]<d[rmq[i+(1<<(j-1))][j-1]])
				rmq[i][j]=rmq[i][j-1];
			else 
				rmq[i][j]=rmq[i+(1<<(j-1))][j-1];
		}
	}
}
int lca(int u,int v) {
	int len=v-u+1;
	int lg=__lg(len);
	//cout<<u<<' '<<v<<' '<<lg<<' '<<rmq[u][lg]<<' '<<rmq[v-(1<<lg)+1][lg]<<endl;
	if (d[rmq[u][lg]]<d[rmq[v-(1<<lg)+1][lg]]) return rmq[u][lg];
	return rmq[v-(1<<lg)+1][lg];
}
long long dist(int u,int v) {
	if (fai[u]>fai[v]) swap(u,v);
    int k=lca(fai[u],fai[v]);
    //cout<<u<<' '<<v<<' '<<k<<' '<<sum[u]<<' '<<sum[v]<<' '<<sum[k]<<endl;
    return sum[u]+sum[v]-2*sum[k];
}
int test;
int used[N+5];
vector<int>dv[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    while (true) {
    	long long res=0;
    	test++;
	    cin>>n;
	    if (n==0) return 0;
	    for (int i=1;i<=n;i++) {
	    	cin>>a[i];
	    	fai[i]=0;
	    	adj[i].clear();
	    }
	    for (int i=1;i<n;i++) {
	    	int u,v,w;
	    	cin>>u>>v>>w;
	    	adj[u].push_back({v,w});
	    	adj[v].push_back({u,w});
	    }
	    cur=0;
	    euler.clear();
	    euler.push_back(0);
	    dfs(1,0);
	    prep();
	    dv[0].clear();
	    for (int i=1;i<=n;i++) {
	    	for (int j=1;j*j<=a[i];j++) {
	    		if (a[i]%j!=0) continue;
	    		if (used[j]!=test) {
	    			used[j]=test;
	    			dv[0].push_back(j);
	    			dv[j].clear();
	    		}
	    		dv[j].push_back(i);
	    		if (j==a[i]/j) continue;
	    		if (used[a[i]/j]!=test) {
	    			used[a[i]/j]=test;
	    			dv[0].push_back(a[i]/j);
	    			dv[a[i]/j].clear();
	    		}
	    		dv[a[i]/j].push_back(i);
	    	}
	    }
	    for (auto g:dv[0]) {
	    	if (dv[g].size()<=1) continue;
	    	int u=dv[g][1];
	    	long long mx=dist(dv[g][0],dv[g][1]);
	    	for (int i=2;i<(int)dv[g].size();i++) {
	    		long long temp=dist(dv[g][0],dv[g][i]);
	    		if (mx<temp) {
	    			mx=temp;
	    			u=dv[g][i];
	    		}
	    	}
	    	//cout<<u<<endl;
	    	for (auto v:dv[g]) {
	    		if (v==u) continue;
	    		mx=max(mx,dist(u,v));
	    		//cout<<u<<' '<<v<<' '<<g<<' '<<dist(u,v)<<endl;
	    	}
	    	//cout<<mx<<' '<<g<<endl;
	    	res=max(res,mx*g);
	    }
	    cout<<res<<'\n';
    }
}