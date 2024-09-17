#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,m;
int a[N+5][N+5];
long long p=2,q=3,mod=1e9+7;
long long hsh[N+5][N+5],powp[N+5],powq[N+5];
void create_hash() {
	for (int i=1;i<=n*2;i++) {
		for (int j=1;j<=m*2;j++) hsh[i][j]=((hsh[i-1][j]*q+hsh[i][j-1]*p-hsh[i-1][j-1]*p*q+a[i][j])%mod+mod)%mod; 
	}
	powp[0]=powq[0]=1;
	for (int i=1;i<=N;i++) {
		powp[i]=powp[i-1]*p%mod;
		powq[i]=powq[i-1]*q%mod;
	}
}
long long get(int x,int y,int u,int v) {
	x--;
	y--;
	return ((hsh[u][v]-hsh[x][v]*powq[u-x]%mod-hsh[u][y]*powp[v-y]%mod+hsh[x][y]*powp[v-y]%mod*powq[u-x]%mod)%mod+mod)%mod;
}
int resx=1,resy=1;
bool check(int x,int y,int len) {
	if (len%m==0) {
		int t=len/m;
		return (get(x,y,x+t-1,y+m-1)!=get(resx,resy,resx+t-1,resy+m-1));
	} else {
		int t=len/m;
		if (t!=0&&get(x,y,x+t-1,y+m-1)!=get(resx,resy,resx+t-1,resy+m-1)) return true;
		int k=len%m;
		return (get(x+t,y,x+t,y+k-1)!=get(resx+t,resy,resx+t,resy+k-1));
	}
}
bool smaller(int x,int y) {
	int lo=1,hi=n*m,ans=-1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(x,y,mid)) {
			ans=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	if (ans==-1) return false;
	int px,py;
	if (ans%m==0) {
		px=ans/m-1;
		py=m-1;
	} else {
		px=ans/m;
		py=ans%m-1;
	}
	//cout<<ans<<' '<<px<<' '<<py<<' '<<a[x+px][y+py]<<' '<<a[resx+px][resy+py]<<endl;
	return (a[x+px][y+py]<a[resx+px][resy+py]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n*2;i++) {
    	for (int j=1;j<=m*2;j++) {
    		if (i<=n&&j<=m) {
		    	char c;
		    	cin>>c;
		    	if (c=='.') a[i][j]=1;
	    	} else {
	    		int pi=i,pj=j;
	    		if (pi>n) pi-=n;
	    		if (pj>m) pj-=m;
	    		a[i][j]=a[pi][pj];
	    	}
	    	//if (a[i][j]) cout<<'.';
    		//else cout<<'*';
    	}
    	//cout<<endl;
    }
    create_hash();
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (i==1&&j==1) continue;
    		if (smaller(i,j)) {
    			resx=i;
    			resy=j;
    		}
    	}
    }
    for (int i=resx;i<=resx+n-1;i++) {
    	for (int j=resy;j<=resy+m-1;j++) {
    		if (a[i][j]) cout<<'.';
    		else cout<<'*';
    	}
    	cout<<'\n';
    }
}