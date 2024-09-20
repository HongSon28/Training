#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int a[N+5][N+5];
int dp2[N+5][N+5];
int dp5[N+5][N+5];
int inf=1e9;
int cnt(int x,int v) {
	int ans=0;
	while (x%v==0) {
		x/=v;
		ans++;
	}
	return ans;
}
pair<int,int>zr;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) {
    		cin>>a[i][j];
    		if (a[i][j]==0) zr={i,j};
    	}
    }
    for (int i=0;i<=n;i++) dp2[i][0]=dp2[0][i]=dp5[i][0]=dp5[0][i]=inf;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) {
    		if (i==1&&j==1) {
    			dp2[i][j]=cnt(a[i][j],2);
    			dp5[i][j]=cnt(a[i][j],5);
    			continue;
    		}
    		if (a[i][j]==0) {
    			dp2[i][j]=dp5[i][j]=inf;
    			continue;
    		}
    		dp2[i][j]=min(dp2[i-1][j],dp2[i][j-1])+cnt(a[i][j],2);
    		dp5[i][j]=min(dp5[i-1][j],dp5[i][j-1])+cnt(a[i][j],5);
    	}
    }
    string res;
    if (zr!=make_pair(0,0)&&1<=min(dp2[n][n],dp5[n][n])) {
    	cout<<1<<'\n';
    	for (int i=1;i<=zr.first-1;i++) cout<<"D";
    	for (int i=1;i<=zr.second-1;i++) cout<<"R";
    	for (int i=1;i<=n-zr.first;i++) cout<<"D";
    	for (int i=1;i<=n-zr.second;i++) cout<<"R";
    	return 0;
    }
    if (dp2[n][n]<dp5[n][n]) {
    	cout<<dp2[n][n]<<'\n';
    	int i=n,j=n;
    	while (i>1||j>1) {
    		if (dp2[i][j]==dp2[i-1][j]+cnt(a[i][j],2)) {
    			i--;
    			res+="D";
    		} else {
    			j--;
    			res+="R";
    		}
    	}
    } else {
    	cout<<dp5[n][n]<<'\n';
    	int i=n,j=n;
    	while (i>1||j>1) {
    		if (dp5[i][j]==dp5[i-1][j]+cnt(a[i][j],5)) {
    			i--;
    			res+="D";
    		} else {
    			j--;
    			res+="R";
    		}
    	}
    }
    reverse(res.begin(),res.end());
    cout<<res;
}