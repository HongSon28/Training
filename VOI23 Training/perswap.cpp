#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,sum,res;
int p[N+5],a[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i];
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (p[i]>p[j]&&i<j) sum++;
			a[i][j]=a[i][j-1];
			if (p[j]>p[i]) a[i][j]++;
		}
	}
	res=sum;
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			if (p[i]<p[j]) continue;
			int cur=sum;
			cur-=((a[j][j]-a[j][i])-(a[i][j]-a[i][i]))*2;
			res=min(res,cur);
		}
	}
	cout<<res;
}