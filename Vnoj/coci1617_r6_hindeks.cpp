#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
int a[N+5],res;
bool check(int k) {
	int cnt=0;
	for (int i=1;i<=n;i++) cnt+=(a[i]>=k);
	return cnt>=k;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	int lo=0,hi=n;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	cout<<res;
}