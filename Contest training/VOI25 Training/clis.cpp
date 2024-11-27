#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
int a[N+5];
int dp[N+5],mx;
long long f[N+5],res,mod=1e9+7;
int bit[N+5];
vector<int>cprs;
vector<int>v[N+5];
void add(long long &x,long long y) {
	x+=y;
	if (x>=mod) x-=mod;
}
void update(int idx,int val) {
	while (idx<=n) {
		bit[idx]=max(bit[idx],val);
		idx+=(idx&(-idx));
	}
}
int get(int idx) {
	int ans=0;
	while (idx>0) {
		ans=max(ans,bit[idx]);
		idx-=(idx&(-idx));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	cprs.push_back(a[i]);
    }	
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    f[0]=1;
    v[0].push_back(0);
    for (int i=1;i<=n;i++) {
    	a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
    	dp[i]=get(a[i]-1)+1;
    	update(a[i],dp[i]);
    	v[dp[i]].push_back(i);
    	for (auto j:v[dp[i]-1]) if (a[j]<a[i]) add(f[i],f[j]);
    	mx=max(mx,dp[i]); 
    }
    for (auto i:v[mx]) add(res,f[i]);
    cout<<res;
}