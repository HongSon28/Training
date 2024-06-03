#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],pre[105][N+5],suf[105][N+5],cnt[105][105],res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		for (int j=1;j<=100;j++) pre[j][i]=pre[j][i-1];
		pre[a[i]][i]++;
	}
	for (int i=n;i>=1;i--) {
		for (int j=1;j<=100;j++) suf[j][i]=suf[j][i+1];
		suf[a[i]][i]++;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=100;j++) {
			long long cur1=suf[j][i+1];
			long long cur2=cnt[j][a[i]];
			res+=cur1*cur2;
			cnt[j][a[i]]+=pre[j][i-1];
		}
	}
	cout<<res;
}