#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,s,t;
int a[N+5],d[N+5];
vector<int>adj[N*2+5];
int id[N+5];
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i)
			for (int j=i*i;j<=N;j+=i) d[j]=min(d[j],i);
	}
} 
queue<int>q;
int trace[N*2+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>n;
    int cur=n;
    for (int i=2;i<=N;i++) {
    	if (d[i]==i) id[i]=++cur;
    }
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	int t=a[i];
    	while (t>1) {
    		int div=d[t];
    		adj[id[div]].push_back(i);
    		adj[i].push_back(id[div]);
    		while (t%div==0) t/=div;
    	}
    }
    cin>>s>>t;
    trace[s]=-1;
    q.push(s);
    while (!q.empty()) {
    	int u=q.front();
    	q.pop();
    	for (auto v:adj[u]) {
    		if (trace[v]!=0) continue;
    		q.push(v);
    		trace[v]=u;
    	}
    }
    if (trace[t]==0) {
    	cout<<-1;
    	return 0;
    }
    vector<int>res;
    res.push_back(t);
    while (res.back()!=s) res.push_back(trace[res.back()]);
    reverse(res.begin(),res.end());
    cout<<((int)res.size()+1)/2<<'\n';
    for (int i=0;i<(int)res.size();i+=2) cout<<res[i]<<' ';
}