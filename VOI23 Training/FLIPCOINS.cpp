#include<bits/stdc++.h>
using namespace std;
int t;
int d[(1<<16)],inf=1e9;
int dx[]={1,-1,0,0,0};
int dy[]={0,0,1,-1,0};
int change(int x,int i,int j) {
	for (int tt=0;tt<5;tt++) {
		int u=i+dx[tt],v=j+dy[tt];
		if (u<0||v<0||u>=4||v>=4) continue;
		int k=u*4+v;
		//cout<<u<<' '<<v<<' '<<k<<endl;
		x^=(1<<k);
	}
	return x;
}
void prep() {
	queue<int>q;
	q.push(0);
	q.push((1<<16)-1);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			for (int j=0;j<4;j++) {
				int v=change(u,i,j);
				//cout<<u<<' '<<i<<' '<<j<<' '<<v<<endl;
				if (d[v]==inf) {
					d[v]=d[u]+1;
					q.push(v);
				}
			}
		}
	}
}
int main() {
	freopen("FLIPCOINS.INP","r",stdin);
	freopen("FLIPCOINS.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    for (int i=1;i<(1<<16)-1;i++) d[i]=inf;
    prep();
    cin>>t;
    while (t--) {
    	int bit=0;
    	for (int i=0;i<4;i++) {
    		for (int j=0;j<4;j++) {
    			char c;
    			cin>>c;
    			if (c=='H') bit|=(1<<(i*4+j));
    		}
    	}
    	if (d[bit]==inf) cout<<"Impossible"<<'\n';
    	else cout<<d[bit]<<'\n';
    }
}
/*
2 1 9
0 1 1
1 2 6
1 0 4
0 1 1 594
*/