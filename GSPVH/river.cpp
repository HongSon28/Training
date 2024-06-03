#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,j;
long long d[N+5],m,res,mx;
bool check(long long k) {
	long long cur=0;
	int i=0,cnt=1;
	while (i<n) {
		if (d[i]+cur<=k) {
			cur+=d[i];
			i++;
		} else {
			cur=d[i];
			i++;
			cnt++;
		}
	}
	return cnt<=j;
}
int main() {
	freopen("river.inp","r",stdin);
	freopen("river.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>j;
    for (long long i=0;i<n;i++) {
    	d[i]=1+i*i%m;
    	mx=max(mx,d[i]);
    }
    long long lo=mx,hi=1e16;
    while (lo<=hi) {
    	long long mid=(lo+hi)/2;
    	if (check(mid)) {
    		res=mid;
    		hi=mid-1;
    	} else lo=mid+1;
    } 
    cout<<res;
}