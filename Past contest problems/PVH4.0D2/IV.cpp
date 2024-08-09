#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int sub,t;
int n,m;
long long s[N+5];
void solve1() {
	long long b=0,r=0;
	int cur=1;
	while (m--) {
		char bp;
		int team;
		cin>>bp>>team;
		if (team==1) b+=s[cur];
		else r+=s[cur];
		cur++;
	}
	cout<<b-r<<'\n';
}
void solve2() {
	long long b=0,r=0;
	int cur=1,cp=0,cb=0;
	for (int i=1;i<=m/2;i++) {
		char bp;
		int team;
		cin>>bp>>team;
		if (bp=='b') cb++;
		else cp++;
	}
	for (int i=1;i<=cp;i++) {
		b+=s[cur];
		cur++;
	}
	cur+=cb;
	for (int i=m/2+1;i<=m;i++) {
		char bp;
		int team;
		cin>>bp>>team;
		if (bp=='p') {
			r+=s[cur];
			cur++;
		}
	}
	cout<<b-r<<'\n';
}
struct query{
	int type,team,val;
};
vector<query>q;
vector<int>v;
void ban(int st,int val) {
	while (val--) v.erase(v.begin()+st);
}
long long pick(int val) {
	long long ans=0;
	while (val--) {
		ans+=v[0];
		v.erase(v.begin());
	}
	return ans;
}
void solve() {
	q.clear();
	v.clear();
	long long b=0,r=0;
	for (int i=1;i<=n;i++) v.push_back(s[i]);
	while (m--) {
		char bp;
		int team,type;
		cin>>bp>>team;
		if (bp=='b') type=1;
		else type=2;
		if (!q.empty()&&q.back().type==type&&q.back().team==team) q[q.size()-1].val++;
		else q.push_back({type,team,1});
	}
	q.push_back({0,0,0});
	for (int i=0;i<(int)q.size()-1;i++) {
		if (q[i].type==1) {
			if (q[i+1].type==1) {
				if (i+2<(int)q.size()-1&&q[i+2].team==q[i].team) ban(q[i+1].val+1,q[i].val);
				else ban(0,q[i].val);
			}
			else if (q[i+1].type==2&&q[i+1].team==q[i].team) ban(q[i+1].val+1,q[i].val);
			else if (q[i+1].type==2&&q[i+1].team!=q[i].team) ban(0,q[i].val);
		} else if (q[i].type==2) {
			if (q[i].team==1) b+=pick(q[i].val);
			else r+=pick(q[i].val);
		}
	}
	cout<<b-r<<'\n';
}
int main() {
	freopen("IV.INP","r",stdin);
	freopen("IV.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>sub>>t;
	while (t--) {
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>s[i];
		sort(s+1,s+1+n,greater<int>());
		if (sub==1) solve1();
		else if (sub==2) solve2();
		else solve();
	}
}