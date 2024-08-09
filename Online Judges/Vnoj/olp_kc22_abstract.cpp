#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m;
int a[N+5][N+5];
bool p[N+5][N+5];
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) cin>>a[i][j];
	}
	for (int i=1;i<=n;i++) {
		int mx=-1;
		for (int j=1;j<=m;j++) {
			if (a[i][j]>mx) p[i][j]=true;
			mx=max(mx,a[i][j]);
		}
		mx=-1;
		for (int j=m;j>=1;j--) {
			if (a[i][j]>mx) p[i][j]=true;
			mx=max(mx,a[i][j]);
		}
	}
	for (int j=1;j<=m;j++) {
		int mx=-1;
		for (int i=1;i<=n;i++) {
			if (a[i][j]>mx) p[i][j]=true;
			mx=max(mx,a[i][j]);
		}
		mx=-1;
		for (int i=n;i>=1;i--) {
			if (a[i][j]>mx) p[i][j]=true;
			mx=max(mx,a[i][j]);
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) res+=a[i][j]&&p[i][j];
	}
	cout<<res;
}