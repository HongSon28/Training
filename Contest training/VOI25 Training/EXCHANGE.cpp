#include<bits/stdc++.h>
using namespace std;
const int N=120000,M=500;
int n,p;
int c[N+5];
bool dp[N+5][M+5];
pair<int,int> trace[N+5][M+5];
vector<int>a,b;
vector<int>res;
void tr(int i,int j) {
	if (i==0) return;
	pair<int,int>t=trace[i][j];
	res.push_back(t.first);
	tr(i-t.first,j-t.second);
}
int main() {
    freopen("EXCHANGE.INP","r",stdin);
	freopen("EXCHANGE.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>p;
	for (int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n);
	a.push_back(c[1]);
	for (int i=2;i<=n;i++) {
		if (c[i]!=c[i-1]) a.push_back(c[i]);
		else b.push_back(c[i]);
	}
	dp[0][0]=true;
	for (auto x:b) {
		for (int i=p*2;i>=x;i--) {
			if (!dp[i][0]&&dp[i-x][0]) {
				dp[i][0]=true;
				trace[i][0]={x,0};
			}
		}
	}
	for (auto x:a) {
		for (int i=p*2;i>=x;i--) {
			for (int j=1;j<=(int)a.size();j++) {
				if (!dp[i][j]&&dp[i-x][j-1]) {
					dp[i][j]=true;
					trace[i][j]={x,1};
				}
			}
		}
	}
	for (int d=0;d<=(int)a.size();d++) {
		for (int i=p;i<=p*2;i++) {
			if (dp[i][d]) {
				tr(i,d);
				cout<<(int)a.size()-d<<' '<<i<<'\n';
				sort(res.begin(),res.end());
				for (auto x:res) cout<<x<<' ';
				return 0;
			}
		}
	}
}