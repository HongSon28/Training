#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m,a,b;
vector<vector<int>>adj(N+5);
struct dat{
	int u,t;
};
queue<dat>nka,nhs;
int vnka[N+5],vnhs[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>a>>b;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    if (a==b){
    	cout<<0;
    	return 0;
    }
    nka.push({a,0});
    nhs.push({b,0});
	for (int i=1;i<=n;i++) {
		while(!nka.empty()&&nka.front().t<i) {
			int u=nka.front().u;
			nka.pop();
			for (auto v:adj[u]) {
				if (vnka[v]==i) continue;
				vnka[v]=i;
				nka.push({v,i});
				//cout<<"NKA"<<' '<<v<<' '<<i<<endl;
			}
		}
		while(!nhs.empty()&&nhs.front().t<i) {
			int u=nhs.front().u;
			nhs.pop();
			for (auto v:adj[u]) {
				if (vnhs[v]==i) continue;
				if (vnka[v]==i) {
					cout<<i;
					return 0;
				}
				vnhs[v]=i;
				nhs.push({v,i});
				//cout<<"NHS"<<' '<<v<<' '<<i<<endl;
			}
		}
	}
	cout<<-1;
}