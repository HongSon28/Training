#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
struct dat{
    long long a,b,ca,cb;
    bool operator < (const dat &other) const {
        if (cb!=other.cb) return cb>other.cb;
        return ca>other.ca;
    }
} p[N+5];
long long dp[N+5],bit[N+5],inf=1e18,mn=inf;
long long f[N+5],res,mod=1e9+7;
vector<int>cprs;
map<long long,vector<int>>v;
void add(long long &x,long long y) {
	x+=y;
	if (x>=mod) x-=mod;
}
void update(int idx,long long val) {
	while (idx>0) {
		bit[idx]=min(bit[idx],val);
		idx-=(idx&(-idx));
	}
}
long long get(int idx) {
	long long ans=inf;
	while (idx<=N) {
		ans=min(ans,bit[idx]);
		idx+=(idx&(-idx));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p[i].a>>p[i].b;
    	cprs.push_back(p[i].a);
    	cprs.push_back(p[i].b);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) {
    	p[i].ca=lower_bound(cprs.begin(),cprs.end(),p[i].a)-cprs.begin()+1;
    	p[i].cb=lower_bound(cprs.begin(),cprs.end(),p[i].b)-cprs.begin()+1;
    }
    for (int i=1;i<=N;i++) bit[i]=inf;
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
    	long long cur=get(p[i].ca);
    	if (cur==inf) {
    		dp[i]=p[i].b;
    		f[i]=1;
    	} else {
    		dp[i]=cur-p[i].a+p[i].b;
    		for (auto j:v[cur]) if (p[j].b>=p[i].a) add(f[i],f[j]);
    	}
    	v[dp[i]].push_back(i);
    	update(p[i].cb,dp[i]);
    	mn=min(mn,dp[i]);
    }
    for (auto i:v[mn]) {
        add(res,f[i]);
    }
    cout<<res;
}
