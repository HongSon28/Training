#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<int,int>p[N+5];
int c[N*2+5];
long long pw[N+5],mod=1e9+7,res;
void add(long long &x,long long y) {
	x+=y;
	if (x>=mod) x-=mod;
}
void prep() {
	pw[0]=1;
	for (int i=1;i<=N;i++) {
		pw[i]=pw[i-1]*2;
		if (pw[i]>=mod) pw[i]-=mod;
	}
}
int main() {
	freopen("help.in","r",stdin);
	freopen("help.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    prep();
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p[i].first>>p[i].second;
    	c[p[i].first]++;
    	c[p[i].second]--;
    }	
    for (int i=1;i<=2*n;i++) c[i]+=c[i-1];
    for (int i=1;i<=n;i++) add(res,pw[n-c[p[i].first]]);
    cout<<res;
}