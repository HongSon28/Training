#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
priority_queue<int,vector<int>,greater<int>>pq;
set<int>s[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	int u,v;
    	cin>>u>>v;
    	s[u].insert(v);
    	s[v].insert(u);
    }	
    for (int i=0;i<=n;i++) {
    	if (s[i].size()==1) pq.push(i);
    }
    for (int i=1;i<=n-1;i++) {
    	int u=pq.top();
    	pq.pop();
    	int v=*s[u].begin();
    	s[v].erase(u);
    	if (s[v].size()==1) pq.push(v);
    	cout<<v<<' ';
    }
}