#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n;
int x[N+5],y[N+5];
int res1,res2,mn=INT_MAX;
int cnt[N+5];
bool check(int i,int j,int k) {
	if (x[i]==x[j]&&x[i]==x[k]) return false;
	if (y[i]==y[j]&&y[i]==y[k]) return false;
	long long t1=x[i]-x[j],t2=y[i]-y[j],t3=x[i]-x[k],t4=y[i]-y[k];
	return !(t1*t4==t2*t3);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
	for (int i=1;i<n-1;i++) {
		for (int j=i+1;j<n;j++) {
			for (int k=j+1;k<=n;k++) {
				if (check(i,j,k)) {
					res1++;
					cnt[i]++;
					cnt[j]++;
					cnt[k]++;
				}
			}
		}
	}
	for (int i=1;i<=n;i++) {
		if (cnt[i]<mn) {
			mn=cnt[i];
			res2=i;
		}
	}
	cout<<res1<<' '<<res2;
}