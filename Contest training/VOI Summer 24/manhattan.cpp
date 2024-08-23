#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
struct dat{
	int x,y,val;
};
vector<dat>a;
vector<int>cprs;
vector<pair<int,int>>p[N+5];
long long b[N+5],c[N+5];
long long res;
long long calc(int v) {
	long long ans=0,cnt=0;
	for (auto [x,y]:p[v]) {
		b[++cnt]=x;
		c[cnt]=y;
	}
	sort(b+1,b+1+cnt);
	sort(c+1,c+1+cnt);
	long long cur=0;
	for (int i=1;i<=cnt;i++) {
		ans+=b[i]*(i-1)-cur;
		cur+=b[i];
	}
	cur=0;
	for (int i=1;i<=cnt;i++) {
		ans+=c[i]*(i-1)-cur;
		cur+=c[i];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			dat t;
			cin>>t.val;
			t.x=i,t.y=j;
			a.push_back(t);
			cprs.push_back(t.val);
		}
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (auto [x,y,val]:a) {
		int t=lower_bound(cprs.begin(),cprs.end(),val)-cprs.begin()+1;
		p[t].push_back({x,y});
	}
	for (int i=1;i<=cprs.size();i++) res+=calc(i);
	cout<<res;
}