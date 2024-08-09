#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m;
int b[N+5],cnt[(1<<16)],cost[(1<<16)],dp[(1<<16)];
bool used[N+5];
vector<int>temp,c;
void rec(int k) {
	for (int i=0;i<n*n;i++) {
		if (used[i]) continue;
		used[i]=true;
		temp.push_back(i);
		if (k<n) rec(k+1);
		else {
			int bit1=0;
			for (auto t:temp) bit1|=(1<<t); 
			int t=0,bit2=0;
			for (int j=temp.size()-1;j>=0;j--) {
				bit2+=(temp[j]<<t);
				t+=4;
			}
			cost[bit1]=max(cost[bit1],cnt[bit2]);
		}
		temp.pop_back();
		used[i]=false;
	}
}
void rec2(int k,int last) {
	for (int i=last;i<n*n;i++) {
		if (used[i]) continue;
		used[i]=true;
		temp.push_back(i);
		if (k<n) rec2(k+1,i+1);
		else {
			int bit=0;
			for (auto t:temp) bit|=(1<<t);
			c.push_back(bit);
		}
		temp.pop_back();
		used[i]=false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("rowmatch.inp","r",stdin);
	freopen("rowmatch.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		cin>>b[i];
		b[i]--;
	}
	for (int i=n;i<=m;i++) {
		int cur=0,t=0;
		for (int j=i;j>=i-n+1;j--) {
			cur+=(b[j]<<t);
			t+=4;
		}
		//cout<<cur<<endl;
		cnt[cur]++;
	}
	rec(1);
	rec2(1,0);
	//for (auto s:c) cout<<s<<' '<<cost[s]<<endl;
	for (int mask=0;mask<(1<<(n*n));mask++) {
		for (auto s:c) {
			if ((mask&s)!=0) continue;
			dp[mask|s]=max(dp[mask|s],dp[mask]+cost[s]);
		}
	}
	cout<<dp[(1<<(n*n))-1];
}