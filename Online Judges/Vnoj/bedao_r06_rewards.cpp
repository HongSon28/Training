#include<bits/stdc++.h>
using namespace std;
const int N=42;
int n,m,p,q;
long long a[N][N][N][N],sum[N][N][N][N];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>p>>q;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		for (int ii=1;ii<=p;ii++) {
    			for (int jj=1;jj<=q;jj++) {
    				cin>>a[i][j][ii][jj];
    				sum[i][j][ii][jj]=a[i][j][ii][jj];
    				for (int mask=1;mask<(1<<4);mask++) {
    					long long cur=sum[i-(mask&1)][j-(mask>>1&1)][ii-(mask>>2&1)][jj-(mask>>3&1)];
    					if (__builtin_popcount(mask)%2==0) sum[i][j][ii][jj]-=cur;
    					else sum[i][j][ii][jj]+=cur;
    				}
    			}
    		}
    	}
    }
    int t;
    cin>>t;
    while (t--) {
    	int x1,y1,z1,t1,x2,y2,z2,t2,x,y,z,t;
    	long long cur,res=0;
    	cin>>x1>>y1>>z1>>t1>>x2>>y2>>z2>>t2;
    	for (int mask=0;mask<(1<<4);mask++) {
    		if (mask&1) x=x1-1;
    		else x=x2;
    		if (mask>>1&1) y=y1-1;
    		else y=y2;
    		if (mask>>2&1) z=z1-1;
    		else z=z2;
    		if (mask>>3&1) t=t1-1;
    		else t=t2;
    		cur=sum[x][y][z][t];
    		if (__builtin_popcount(mask)%2==0) res+=cur;
    		else res-=cur; 
    		//cout<<x<<' '<<y<<' '<<z<<' '<<t<<' '<<cur<<' '<<res<<endl;
    	}
    	cout<<res<<'\n';
    }
}