#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,m;
char c[N+5][N+5];
int l[N+5][N+5],r[N+5][N+5];
int cnt[N+5][N+5],cl[N+5][N+5],cr[N+5][N+5];
long long res,sum;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		cin>>c[i][j];
    		cnt[i][j]=cnt[i][j-1]+(c[i][j]=='#');
    		sum+=(c[i][j]=='*');
    	}
    }
    for (int i=1;i<=n;i++) { 
    	for (int j=1;j<=m;j++) {
    		if (c[i][j]=='#') continue;
    		if (j>=2&&c[i][j-1]=='*') l[i][j]=l[i][j-1];
    		else if (i>=2&&c[i-1][j]=='*') l[i][j]=l[i-1][j]+j;
    		else l[i][j]=j;
    	}
    }
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (c[i][j]=='#') continue;
    		if (i>=2&&c[i-1][j]=='*') r[i][j]=r[i-1][j]+j+1;
    		else if (j>=2&&c[i][j-1]=='*') r[i][j]=r[i][j-1]+1;
    		else r[i][j]=j+1;
    	}
    }
    for (int i=1;i<=n;i++) { 
    	for (int j=1;j<=m;j++) {
    		if (j>=2&&c[i][j-1]=='*') cl[i][j]=cl[i][j-1]+(c[i][j-1]=='#');
    		else if (i>=2&&c[i-1][j]=='*') cl[i][j]=cl[i-1][j]+cnt[i][j-1];
    		else cl[i][j]=0;
    		if (i>=2&&c[i-1][j]=='*') cr[i][j]=cr[i-1][j]+cnt[i][j];
    		else if (j>=2&&c[i][j-1]=='*') cr[i][j]=cr[i][j-1]+(c[i][j]=='#');
    		else cr[i][j]=(c[i][j]=='#');
    	}
    }
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (c[i][j]!='#') res+=r[i][j]-l[i][j]-(cr[i][j]-cl[i][j])-1;
    		//cout<<l[i][j]<<' '<<r[i][j]<<' '<<cl[i][j]<<' '<<cr[i][j]<<endl;
    	}
    }
    cout<<sum*(sum-1)/2-res;
}