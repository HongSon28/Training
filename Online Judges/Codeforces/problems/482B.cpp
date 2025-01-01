#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
struct dat{
	int l,r,q;
} a[N+5];
int d[31][N+5],sum[31][N+5];
int res[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	cin>>a[i].l>>a[i].r>>a[i].q;
    	for (int j=0;j<=30;j++) {
    		if (a[i].q>>j&1) {
	    		d[j][a[i].l]++;
	    		d[j][a[i].r+1]--;
	    	}
    	}
    }
    for (int i=0;i<=30;i++) {
    	for (int j=1;j<=n;j++) d[i][j]+=d[i][j-1];
    	for (int j=1;j<=n;j++) {
    		d[i][j]=(d[i][j]>0);
    		sum[i][j]=sum[i][j-1]+d[i][j];
    	}
    	for (int j=1;j<=m;j++) {
    		if (!(a[j].q>>i&1)) {
    			if (sum[i][a[j].r]-sum[i][a[j].l-1]==a[j].r-a[j].l+1) {
    				cout<<"NO";
    				return 0;
    			}
    		}
    	}
    	for (int j=1;j<=n;j++) 
    		if (d[i][j]) res[j]+=(1<<i);
    }
    cout<<"YES"<<'\n';
    for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}