#include<bits/stdc++.h>
using namespace std;
const int N=500;
int t,n,q;
vector<vector<int>>adj(N+5);
int main() {
	cin>>t;
	while (t--) {
		cin>>n>>q;
		for (int i=1;i<n;i++) {
			adj[i].push_back(i+1);
			adj[i+1].push_back(i);
			cout<<i<<' '<<i+1<<'\n';
		}
		int t[4];
		t[1]=(n-1)/2;
		t[2]=(n-1)-(n-1)/2;
		t[3]=0;
		while (q--) {
			int d;
			cin>>d;
			if (t[1]+t[2]==d||t[1]+t[3]==d||t[2]+t[3]==d) {
				cout<<"-1 -1 -1"<<'\n';
				continue;
			}
			if (t[1]+t[2]>d) {
				int k=t[1]+t[2]-d;
				t[1]-=k;
				int u=last[1];
				for (i=1;i<=k;i++) {
					u=adj[u][0];
				}
				int v1=adj[u][0];
				cout<<u<<' '<<v1<<' '<<last[3]<<'\n';
				last[3]=last[1];
				last[1]=v1;
				t[3]+=k;
			} else if (t[1]+t[3]>d) {
				int k=t[1]+t[3]-d;
				t[1]-=k;
				int u=last[1];
				for (i=1;i<=k;i++) {
					u=adj[u][0];
				}
				int v1=adj[u][0];
				cout<<u<<' '<<v1<<' '<<last[2]<<'\n';
				last[2]=last[1];
				last[1]=v1;
				t[2]+=k;
			} else if (t[2]+t[3]>d) {
				int k=t[2]+t[3]-d;
				t[2]-=k;
				int u=last[2];
				for (i=1;i<=k;i++) {
					u=adj[u][0];
				}
				int v1=adj[u][0];
				cout<<u<<' '<<v1<<' '<<last[1]<<'\n';
				last[1]=last[2];
				last[2]=v1;
				t[1]+=k;
			} else {
				int k=d-(t[1]+t[2]);
			}
		}
	}
}