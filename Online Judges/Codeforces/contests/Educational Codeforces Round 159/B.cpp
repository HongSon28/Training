#include<bits/stdc++.h>
using namespace std;
int tc;
long long n,p,l,t;
bool check(long long day) {
	long long test=(n+6)/7;
	test=min(test,day*2);
	return (test*t+l*day>=p);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>tc;
    while (tc--) {
    	cin>>n>>p>>l>>t;
    	long long lo=0,hi=n,res=0;
    	while (lo<=hi) {
    		long long mid=(lo+hi)/2;
    		if (check(mid)) {
    			res=mid;
    			hi=mid-1;
    		} else lo=mid+1;
    	}
    	cout<<n-res<<'\n';
    }	
}