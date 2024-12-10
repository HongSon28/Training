#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n,m,k;
char c[N+5][N+5],d[N+5][N+5];
int f[N+5][N+5][N+5],g[N+5][N+5][N+5];
void calc(char a[],int len,int res[N+5][N+5]){
	int nk=0;
	int b[N+5];
	b[0]=0;
	for (int i=1;i<=len;i++) if (a[i]=='*') b[++nk]=i;
	b[nk+1]=len+1;
	pair<int,int> st[N+5];
	for (int k=0;k<=nk;k++) {
		int fr=1,bk=0,l=0;
		for (int j=1;j<=len;j++) {
			while (l+k<=nk&&b[l]<j) {
				while (bk>=fr&&b[l+k+1]-b[l]>st[bk].first) bk--;
				st[++bk]={b[l+k+1]-b[l]-1,b[l+k+1]-1};
				l++;
			}
			while (fr<=bk&&st[fr].second<j) fr++;
			res[j][k]=st[fr].first;
		}
	}
	for (int i=1;i<=len;i++)
		for (int j=nk+1;j<=k;j++)
			res[i][j]=len;
}
int main() {
	freopen("BANYAN.INP","r",stdin);
	freopen("BANYAN.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		cin>>c[i][j];
    		d[j][i]=c[i][j];
    	}
    }
    for (int i=1;i<=n;i++) calc(c[i],m,f[i]);
    for (int j=1;j<=m;j++) calc(d[j],n,g[j]);
    int res=0;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (k==0&&c[i][j]=='*') continue;
    		int cur=k+(c[i][j]=='*');
    		for (int t=0;t<=cur;t++) {
    			res=max(res,f[i][j][t]+g[j][i][cur-t]-1);
    		}
    	}
    }
    cout<<res;
}