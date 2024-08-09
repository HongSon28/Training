#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long l,res;
long long a[N+5],b[N+5];
bool check(long long m) {
	long long cnt=0;
	for (int i=1;i<=n;i++) {
		if (a[i]>=m) continue;
		long long dif=m-a[i];
		cnt+=(dif+b[i]-1)/b[i];
	}
	return (cnt<=l);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>l;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    long long lo=0,hi=1e16;
    while (lo<=hi) {
    	long long mid=(lo+hi)/2;
    	if (check(mid)) {
    		lo=mid+1;
    		res=mid;
    	} else hi=mid-1;
    }
    cout<<res;
}