#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,m;
string x,y;
vector<pair<char,long long>>vx,vy;
namespace task1{
	long long g[N+5][N+5],res;
	int px[27][N+5],py[27][N+5];
	void solve() {
		for (int i=1;i<=n;i++) {
			for (int j=0;j<=26;j++) px[j][i]=px[j][i-1];
			px[vx[i].first-'a'][i]=i;
		}
		for (int i=1;i<=m;i++) {
			for (int j=0;j<=26;j++) py[j][i]=py[j][i-1];
			py[vy[i].first-'a'][i]=i;
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (vx[i].first!=vy[j].first) continue;
				g[i][j]=min(vx[i].second,vy[j].second);
				int v=j-1;
				long long sumx=vx[i].second,sumy=vy[j].second;
				for (int u=i-1;u>=1;u--) {
					while (v>=1&&sumy<sumx) {
						if (vy[v].first==vy[j].first) sumy+=vy[v].second;
						v--;
					}
					if (v==0) break;
					int pos=py[vx[u].first-'a'][v];
					if (pos!=0) g[i][j]=max(g[i][j],sumx+g[u][pos]);
					if (vx[u].first==vx[i].first) sumx+=vx[u].second;
				}
				int u=i-1;
				sumx=vx[i].second,sumy=vy[j].second;
				for (int v=j-1;v>=1;v--) {
					while (u>=1&&sumx<sumy) {
						if (vx[u].first==vx[i].first) sumx+=vx[u].second;
						u--;
					}
					if (u==0) break;
					int pos=px[vy[v].first-'a'][u];
					if (pos!=0) g[i][j]=max(g[i][j],sumy+g[pos][v]);
					if (vy[v].first==vy[j].first) sumy+=vy[v].second;
				}
				sumx=sumy=0;
				for (int u=1;u<=i;u++) if (vx[u].first==vx[i].first) sumx+=vx[u].second;
				for (int v=1;v<=j;v++) if (vy[v].first==vy[j].first) sumy+=vy[v].second;
				g[i][j]=max(g[i][j],min(sumx,sumy));
				res=max(res,g[i][j]);
				//cout<<i<<' '<<j<<' '<<g[i][j]<<endl;
			}
		}
		cout<<res<<'\n';
	}
}
namespace task2{
	long long f[N+5][N+5],res;
	void solve() {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (vx[i].first!=vy[j].first) continue;
				f[i][j]=min(vx[i].second,vy[j].second);
				if (vx[i].second==vy[i].second) f[i][j]=max(f[i][j],f[i-1][j-1]+vx[i].second);
				if (i<n&&j<m&&vx[i+1].first==vy[j+1].first) res=max(res,f[i][j]+min(vx[i+1].second,vy[j+1].second));
				else res=max(res,f[i][j]);
			}
		}
		cout<<res;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>x>>y;
    x=' '+x,y=' '+y;
    long long cur=0;
    char last=' ';
    for (int i=1;i<(int)x.size();i++) {
    	if (x[i]>='0'&&x[i]<='9') {
    		cur*=10;
    		cur+=x[i]-'0';
    	} else {
    		vx.push_back({last,cur});
    		cur=0;
    		last=x[i];
    	}
    }
    vx.push_back({last,cur});
    cur=0;
    last=' ';
    for (int i=1;i<(int)y.size();i++) {
    	if (y[i]>='0'&&y[i]<='9') {
    		cur*=10;
    		cur+=y[i]-'0';
    	} else {
    		vy.push_back({last,cur});
    		cur=0;
    		last=y[i];
    	}
    }
    vy.push_back({last,cur});
    n=vx.size()-1,m=vy.size()-1;
    //for (auto [u,v]:vx) cout<<u<<' '<<v<<endl;
    //for (auto [u,v]:vy) cout<<u<<' '<<v<<endl;
    task1::solve();
    task2::solve();
}