#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m;
long long a[N+5][N+5],sum[N+5][N+5];
long long res,cnt[10];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		cin>>a[i][j];
    		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    	}
    }	
    for (int i1=1;i1<=n;i1++) {
    	for (int i2=i1;i2<=n;i2++) {
    		memset(cnt,0,sizeof(cnt));
    		cnt[0]++;
    		for (int j=1;j<=m;j++) {
    			long long temp=sum[i2][j]-sum[i1-1][j];
    			temp%=9;
    			res+=cnt[temp];
    			cnt[temp]++;
    		}
    	}
    }
    cout<<res;
}