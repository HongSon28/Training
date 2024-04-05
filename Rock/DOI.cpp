#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int l1[N+5],l2[N+5],r2[N+5],r1[N+5],res1,res2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=2;i<=n;i++) {
		if (a[i]>a[i-1]) l1[i]=l1[i-1]+1;
		else if (a[i]<a[i-1]) l2[i]=l2[i-1]+1;
	}
	for (int i=n-1;i>=1;i--) {
		if (a[i]>a[i+1]) r1[i]=r1[i+1]+1;
		else if (a[i]<a[i+1]) r2[i]=r2[i+1]+1;
	}
	for (int i=2;i<n;i++) {
		int temp=min(l1[i],r1[i]);
		res1=max(res1,temp);
		temp=min(l2[i],r2[i]);
		res2=max(res2,temp);
	}
	cout<<res1<<' '<<res2;
}