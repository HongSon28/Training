#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,k;
int a[N+5],s[N+5];
bool check(int v) {
	int cur=1;
	for (int i=1;i<=n;i++) {
		if (cur&1&&a[i]<=v) {
			s[cur]=a[i];
			cur++;
		} else if (cur%2==0) {
			s[cur]=a[i];
			cur++;
		}
	}
	if (cur>k) return true;
	cur=2;
	s[1]=a[1];
	for (int i=2;i<=n;i++) {
		if (cur%2==0&&a[i]<=v) {
			s[cur]=a[i];
			cur++;
		} else if (cur&1) {
			s[cur]=a[i];
			cur++;
		}
	}
	return (cur>k);
} 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	int lo=1,hi=1e9,res=1e9;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	cout<<res;
}