#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,k;
int a[N+5],mod=5000000;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
struct fenwick{
	int bit[N+5];
	void update(int idx,int val) {
		idx++;
		while (idx<=N) {
			add(bit[idx],val);
			idx+=idx&-idx;
		}
	}
	int get(int idx) {
		idx++;
		int res=0;
		while (idx>0) {
			add(res,bit[idx]);
			idx-=idx&-idx;
		}
		return res;
	}
} tree[51];
int dp[N+5][51],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	dp[i][1]=1;
    	tree[1].update(a[i],dp[i][1]);
    	for (int j=2;j<=min(i,k);j++) {
    		dp[i][j]+=tree[j-1].get(a[i]-1);
    		//cout<<i<<' '<<j<<' '<<tree[j-1].get(a[i]-1)<<endl;
    		dp[i][j]%=mod;
    		if (j<k) tree[j].update(a[i],dp[i][j]);
    		else add(res,dp[i][k]);
    	}
    }
    cout<<res;
}