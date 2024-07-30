#include<bits/stdc++.h>
using namespace std;
const int N=1e5,SZ=316;
int n,q,nB;
int block[N+5];
long long a[N+5],s[N+5],lazy[SZ+5],b[SZ+5],c[SZ+5][N+5];
int l[N+5],r[N+5];
long long f(int i) {
	long long t2=s[r[i]]+lazy[block[r[i]]];
	long long t1=s[l[i]-1]+lazy[block[l[i]-1]];
	return t2-t1;
}
int main() {
	//freopen("FNCS.inp","r",stdin);
    //freopen("FNCS.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    nB=n/SZ;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	s[i]=s[i-1]+a[i];
    	block[i]=(i+SZ-1)/SZ;
    }
    for (int i=1;i<=nB*SZ;i++) {
    	cin>>l[i]>>r[i];
    	b[block[i]]+=f(i);
    	c[block[i]][l[i]]++;
    	c[block[i]][r[i]+1]--;
    }
    for (int i=nB*SZ+1;i<=n;i++) cin>>l[i]>>r[i];
    for (int i=1;i<=nB;i++)
    	for (int j=2;j<=n;j++)
    		c[i][j]+=c[i][j-1];
    cin>>q;
    while (q--) {
    	int type;
    	long long x,y;
    	cin>>type>>x>>y;
    	if (type==1) {
    		long long delta=y-a[x];
    		a[x]=y;
    		for (int i=x;i<=min(n,block[x]*SZ);i++) s[i]+=delta;
    		for (int i=block[x]+1;i<=nB;i++) lazy[i]+=delta;
    		if (nB!=0&&block[x]<=nB) for (int i=nB*SZ+1;i<=n;i++) s[i]+=delta;
    		for (int i=1;i<=nB;i++) b[i]+=delta*c[i][x];
    	} else {
    		long long res=0;
    		if (block[x]==block[y]) for (int i=x;i<=y;i++) res+=f(i);
    		else {
    			for (int i=block[x]+1;i<=block[y]-1;i++) res+=b[i];
    			//cout<<res<<' ';
    			for (int i=x;i<=block[x]*SZ;i++) res+=f(i);
    			//cout<<res<<' ';
    			for (int i=(block[y]-1)*SZ+1;i<=y;i++) res+=f(i);
    		}
    		cout<<res<<'\n';
    	}
    }
}
