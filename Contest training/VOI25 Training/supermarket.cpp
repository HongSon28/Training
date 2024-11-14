#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,m,d,k;
pair<long long,long long>a[N+5],b[N+5]; 
namespace sub1{
	const int M=5e4;
	long long dp[M+5][16],inf=1e18;
	long long pos[M+5],sum[M+5];
	vector<long long>v;
	long long res;
	long long cost(int l,int r) {
		int len=r-l+1;
		if (len%2==1) {
			len/=2;
			int mid=l+len;
			return (sum[r]-sum[mid])-(sum[mid-1]-sum[l-1]);
		} else {
			len/=2;
			return (sum[r]-sum[l+len-1])-(sum[l+len-1]-sum[l-1]);
		}
	}
	bool comp(pair<long long,long long>x,pair<long long,long long>y) {
		return x.second<y.second;
	}
	void solve() {
		v.push_back(-inf);
		for (int i=1;i<=d;i++) {
			v.push_back(a[i].first);
			v.push_back(b[i].first);
		}
		sort(v.begin(),v.end());
		int px=(v[d]+v[d+1])/2;
		for (int i=1;i<(int)v.size();i++) res+=abs(v[i]-px);
		sort(a+1,a+1+d,comp);
		sort(b+1,b+1+d);
		for (int i=1;i<=d;i++) {
			pos[i]=a[i].second;
			sum[i]=sum[i-1]+pos[i];
		}
		k=min(k,d);
		for (int i=0;i<=d;i++) 
			for (int j=0;j<=k;j++) dp[i][j]=inf;
		dp[0][0]=0;
		for (int i=1;i<=d;i++) {
			for (int j=0;j<i;j++) {
				long long cst=cost(j+1,i);
				for (int t=1;t<=k;t++) {
					dp[i][t]=min(dp[i][t],dp[j][t-1]+cst);
				}
			}
		}
		cout<<res+dp[d][k]*2;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>d>>k;
	for (int i=1;i<=d;i++) cin>>a[i].first>>a[i].second;
	for (int i=1;i<=d;i++) cin>>b[i].first>>b[i].second;
	sub1::solve();
}