#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int t,n;
long long a[N+5];
long long mx[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	long long cur=0;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		cur+=a[i];
    		mx[i]=max(mx[i-1],cur);
    	}
    	cur=0;
    	long long res=0,m=0;
    	for (int i=n;i>=1;i--) {
    		cur+=a[i];
    		if (max(cur,0ll)+mx[i-1]>m) {
    			m=max(cur,0ll)+mx[i-1];
    			res=mx[i-1];
    		}
    	}
    	cout<<res<<'\n';
    }
}