#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int res;
int n,l;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>l>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if (a[1]>0) res=a[1];
	if (a[n]<l) res=max(res,l-a[n]);
	for (int i=2;i<=n;i++) res=max(res,(a[i]-a[i-1])/2);
	cout<<res;
}