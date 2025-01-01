#include<bits/stdc++.h>
using namespace std;
const int N=600;
int n;
bool p[N+5][N+5];
namespace sub1{
	bool check() {
		return (n<=8);
	}
	int res;
	int con[N+5];
	vector<pair<int,int>>vc;
	bool check(int k) {
		if (k!=n-1) return false;
		for (int i=1;i<=n;i++) if (!con[i]) return false;
		for (int i=0;i<(int)vc.size();i++) {
			for (int j=0;j<(int)vc.size();j++) {
				if (vc[i].first>vc[j].first&&vc[i].first<vc[j].second&&vc[i].second>vc[j].second) {
					//cout<<vc[i].first<<' '<<vc[i].second<<' '<<vc[j].first<<' '<<vc[j].second<<endl;
					return false;
				}
			}
		}
		return true;
	}
	void rec(int i,int j,int cur) {
		if (i==n) {
			res+=check(cur);
			return;
		}
		if (j==n) rec(i+1,i+2,cur);
		else rec(i,j+1,cur);
		if (cur==n-1||!p[i][j]) return;
		con[i]++,con[j]++;
		vc.push_back({i,j});
		if (j==n) rec(i+1,i+2,cur+1);
		else rec(i,j+1,cur+1);
		vc.pop_back();
		con[i]--,con[j]--;
	}
	void solve() {
		rec(1,2,0);
		cout<<res;
	}
}
int main() {
	freopen("DRAWATREE.INP","r",stdin);
	freopen("DRAWATREE.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<n;i++) {
		for (int j=i+1;j<=n;j++) {
			char c;
			cin>>c;
			p[i][j]=(c=='Y');
		}
	}
	sub1::solve();
}