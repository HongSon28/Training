//#include "crocodilelib.h"
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<vector<pair<int,int>>>adj(N+5);
int inf=1e9+5;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
pair<int,int> d1[N+5],d2[N+5],temp[3];
bool update(pair<int,int> &m1,pair<int,int> &m2,const pair<int,int> &m3) {
	temp[0]=m1,temp[1]=m2,temp[2]=m3;
	sort(temp,temp+3);
	m1=temp[0];
	pair<int,int>last=m2;
	if (temp[1].second!=m1.second) m2=temp[1];
	else m2=temp[2];
	return m2.first<last.first;
}
int solve(int n, const vector<int> &u, const vector<int> &v, const vector<int> &l, const vector<int> &p){
	for (int i=0;i<(int)u.size();i++) {
		adj[u[i]+1].push_back({v[i]+1,l[i]});
		adj[v[i]+1].push_back({u[i]+1,l[i]});
	}
	for (int i=1;i<=n+1;i++) 
		d1[i]=d2[i]={inf,-1};
	for (auto u:p) {
		d1[u+1]=d2[u+1]={0,0};
		pq.push({0,u+1});
	}
	while (!pq.empty()) {
		int d=pq.top().first,u=pq.top().second;
		pq.pop();
		//cout<<u<<' '<<d<<' '<<d1[u]<<' '<<d2[u]<<endl;
		if (d!=d2[u].first) continue;
		for (auto [v,w]:adj[u]) {
			if (update(d1[v],d2[v],{d+w,u})) pq.push({d2[v].first,v});
			//cout<<u<<' '<<v<<' '<<d1[v].first<<' '<<d2[v].first<<endl;
		}
	}
	return d2[1].first;
}
int main() {
	int t;
	cin>>t;
	cout<<solve(5, {0, 0, 3, 2}, {1, 2, 2, 4}, {2, 3, 1, 4}, {1, 3, 4});
}