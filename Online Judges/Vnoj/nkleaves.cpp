#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
long long w[N+5],sum[N+5],p[N+5];
vector<long long>dp_before(N+5),dp_cur(N+5);
long long C(int j,int i) {
	return p[i]-p[j-1]-(sum[i]-sum[j-1])*j;
}
void calc(int l,int r,int optl,int optr) {
	if (l>r) return;
	int mid=(l+r)/2;
	pair<long long,int>best={LLONG_MAX,-1};
	for (int opt=optl;opt<=min(mid,optr);opt++) {
		best=min(best,{dp_before[opt-1]+C(opt,mid),opt});
	}
	dp_cur[mid]=best.first;
	int opt=best.second;
	calc(l,mid-1,optl,opt);
	calc(mid+1,r,opt,optr);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>w[i];
    	p[i]=p[i-1]+w[i]*i;
    	sum[i]=sum[i-1]+w[i];
    }
    for (int i=1;i<=n;i++) dp_before[i]=C(1,i);
    for (int i=2;i<=k;i++) {
    	calc(1,n,1,n);
    	dp_before=dp_cur;
    }
    cout<<dp_before[n];
}