#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
long long a[N+5];
bool check1(long long k) {
	long long cur=0;
	for (int i=1;i<=n;i++) {
		if (a[i]>k) cur+=a[i]-k;
		else {
			long long temp=k-a[i];
			temp=min(temp,cur);
			cur-=temp;
		}
	}
	return (cur==0);
}
bool check2(long long k) {
	long long cur=0;
	for (int i=n;i>=1;i--) {
		if (a[i]<k) cur+=k-a[i];
		else {
			long long temp=a[i]-k;
			temp=min(temp,cur);
			cur-=temp;
		}
	}	
	return (cur==0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	long long lo=1,hi=1e12;
    	long long resmx=1e12;
    	while (lo<=hi) {
    		long long mid=(lo+hi)/2;
    		if (check1(mid)) {
    			resmx=mid;
    			hi=mid-1;
    		} else lo=mid+1;
    	}
    	lo=1,hi=resmx;
    	long long resmn=1;
    	while (lo<=hi) {
    		long long mid=(lo+hi)/2;
    		if (check2(mid)) {
    			resmn=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    	cout<<resmx-resmn<<'\n';
    }
}