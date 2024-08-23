#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int r,c,h,w;
int a[N+5][N+5];
int b[N+5][N+5];
int sum[N+5][N+5];
int res;
bool check(int k) {
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			if (a[i][j]>=k) b[i][j]=1;
			else b[i][j]=-1;
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];
		}
	}
	for (int i=h;i<=r;i++) {
		for (int j=w;j<=c;j++) {
			int cur=sum[i][j]-sum[i-h][j]-sum[i][j-w]+sum[i-h][j-w];
			if (cur>0) return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>r>>c>>h>>w;
    for (int i=1;i<=r;i++)
    	for (int j=1;j<=c;j++)
    		cin>>a[i][j];
    int lo=1,hi=r*c;
    while (lo<=hi) {
    	int mid=(lo+hi)/2;
    	if (check(mid)) {
    		res=mid;
    		lo=mid+1;
    	} else hi=mid-1;
    }
    cout<<res;
}