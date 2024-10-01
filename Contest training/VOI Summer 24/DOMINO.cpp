#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5],b[N+5],t[6];
int rev[N+5];
vector<pair<int,int>>v;
bool dp[N+5];
int sum;
int trace[N+5],cnt[6];
void tr(int s) {
	if (s==0) return;
	pair<int,int>p=v[trace[s]];
	cnt[p.first]+=p.second;
	tr(s-p.first*p.second);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		cin>>b[i];
		if (b[i]>a[i]) {
			rev[i]=true; 
			swap(a[i],b[i]);
		}
		t[a[i]-b[i]]++;
		sum+=a[i]-b[i];
	}
	for (int i=1;i<=5;i++) {
		int cur=1,sum=0;
		while (cur+sum<=t[i]) {
			v.push_back({i,cur});
			sum+=cur;
			cur*=2;
		}
		if (t[i]>sum) v.push_back({i,t[i]-sum});
	}
	dp[0]=true;
	for (int i=0;i<(int)v.size();i++) {
		int val=v[i].first*v[i].second;
		for (int s=sum/2;s>=val;s--) {
			if (dp[s-val]&&!dp[s]) {
				dp[s]=true;
				trace[s]=i;
			}
		}
	}
	for (int i=sum/2;i>=0;i--) {
		if (dp[i]) {
			vector<int>res;
			cout<<sum-i*2<<'\n';
			tr(i);
			for (int j=1;j<=n;j++) {
				if (cnt[a[j]-b[j]]>0) {
					cnt[a[j]-b[j]]--;
					rev[j]=1-rev[j];
				}
				if (rev[j]) res.push_back(j);
			}
			cout<<res.size()<<' ';
			for (auto x:res) cout<<x<<' ';
			return 0;
		}
	}
}