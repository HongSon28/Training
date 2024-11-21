#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,q,k;
int a[N+5],sum[N+5];
pair<int,int>p[N+5];
int inf=2e9;
void update(int &l,int &r,int &res,int x,int y) {
	int sx=p[x].first,sy=p[y].first;
	if (abs(abs(sy-sx)-k)<res) {
		res=abs(abs(sy-sx)-k);
		l=x,r=y;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>q;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		sum[i]=sum[i-1]+a[i];
    		p[i]={sum[i],i};
    	}
    	p[0]={0,0};
    	sort(p,p+1+n);
    	while (q--) {
    		int res=inf;
    		int resl,resr;
    		cin>>k;
    		int l=0;
    		for (int r=1;r<=n;r++) {
    			while (l+1<r&&p[l+1].first<=p[r].first-k) l++;
    			if (l+1<r) update(resl,resr,res,l+1,r);
    			update(resl,resr,res,l,r);
    			if (l-1>=0) update(resl,resr,res,l-1,r);
    		}
    		resr=p[resr].second,resl=p[resl].second;
    		if (resr<resl) swap(resr,resl);
    		cout<<abs(sum[resr]-sum[resl])<<' '<<resl+1<<' '<<resr<<'\n';
    	}
    }
}