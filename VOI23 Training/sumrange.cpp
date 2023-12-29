#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n;
long long a[N+5],b[N+5],suma[N+5],sumb[N+5];
long long c[N+5][N+5],sum[N+5][N+5],res=LLONG_MIN;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
    	suma[i]=suma[i-1]+a[i];
    }
    for (int i=1;i<=n;i++){
    	cin>>b[i];
    	sumb[i]=sumb[i-1]+b[i];
    }
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) {
    		if (i<=j) c[i][j]=suma[j]-suma[i-1];
    		else c[i][j]=sumb[i]-sumb[j-1];
    		sum[i][j]=sum[i][j-1]+c[i][j];
    	}
    }
    for (int i=1;i<=n;i++) {
    	for (int j=i;j<=n;j++) {
    		long long mn=0,cur=0;
    		for (int k=1;k<=n;k++) {
    			cur+=sum[k][j]-sum[k][i-1];
    			res=max(res,cur-mn);
    			mn=min(mn,cur);
    		}
    	}
    }
    cout<<res;
}