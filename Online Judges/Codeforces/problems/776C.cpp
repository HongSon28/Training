#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long k;
long long a[N+5];
long long power[N+5],lg,sum;
map<long long,long long>cnt;
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;	
    if (k==1) {
    	power[0]=1;
    } else if (k==-1) {
    	power[0]=1;
    	power[1]=-1;
    	lg=1;
    } else {
    	power[0]=1;
	    while (power[lg]<=(long long)1e18) {
	    	lg++;
	    	power[lg]=power[lg-1]*k;
	    }
	    lg--;
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    cnt[0]++;
    for (int i=1;i<=n;i++) {
    	sum+=a[i];
    	for (int j=0;j<=lg;j++) res+=cnt[sum-power[j]];
    	cnt[sum]++;
    }
    cout<<res;
}