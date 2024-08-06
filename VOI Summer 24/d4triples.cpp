#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int t,n,m;
int a[N+5][N+5];
long long c[3][N+5],r[3][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	long long res=0;
    	cin>>n>>m;
    	for (int i=1;i<=n;i++) {
    		for (int j=1;j<=m;j++) {
    			char c;
    			cin>>c;
    			a[i][j]=c-'0';
    		}
    		r[0][i]=r[1][i]=r[2][i]=0;
    	}
    	for (int i=1;i<=m;i++) c[0][i]=c[1][i]=c[2][i]=0;
    	for (int i=1;i<=n;i++) {
    		for (int j=1;j<=m;j++) {
    			r[a[i][j]][i]++;
    			c[a[i][j]][j]++;
    		}
    	}
    	for (int i=1;i<=n;i++) {
    		for (int j=1;j<=m;j++) {
    			if (!a[i][j]) continue;
    			res+=r[1][i]*c[1][j]+r[2][i]*c[2][j];
    			res-=r[a[i][j]][i]*c[a[i][j]][j];
    		}
    	}
    	cout<<res<<'\n';
    }
}