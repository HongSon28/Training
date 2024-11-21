#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long a[N+5],b[N+5],ta[N+5],tb[N+5];
pair<long long,long long>res;
long long mx;
bool check(long long xp,long long kp,long long xc,long long kc) {
	for (int i=1;i<=n;i++) {
		ta[i]=a[i]+xc,tb[i]=b[i]+xp;
	}
	ta[kc]+=m-n*xc;
	tb[kp]+=m-n*xp;
	int c1=0,c2=0;
	for (int i=1;i<=n;i++) {
		if (ta[i]<tb[i]) c1++;
		if (ta[i]>tb[i]) c2++;
	} 
	return (c1>c2);
}
int main() {
	freopen("CARD.INP","r",stdin);
	freopen("CARD.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (long long xp=0;xp<=m/n;xp++) {
    	for (long long kp=1;kp<=n;kp++) {
    		long long cur=0;
    		for (long long xc=0;xc<=m/n;xc++) {
    			for (long long kc=1;kc<=n;kc++) 
    				cur+=check(xp,kp,xc,kc);
    		}
    		if (cur>mx) {
    			mx=cur;
    			res={xp,kp};
    		} else if (cur==mx) res=min(res,{xp,kp});
    	}
    }
    cout<<res.first<<' '<<res.second<<' '<<mx;
}