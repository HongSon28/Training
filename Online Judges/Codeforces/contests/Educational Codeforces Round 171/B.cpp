#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int t,n;
long long a[N+5];
vector<long long>v;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	if (n==1) {
    		cout<<1<<'\n';
    		continue;
    	}
    	if (n%2==0) {
    		long long res=0;
    		for (int i=2;i<=n;i+=2) res=max(res,a[i]-a[i-1]);
    		cout<<res<<'\n';
    	} else {
    		long long res=1e18;
    		for (int i=1;i<=n;i++) {
    			v.clear();
    			long long cur=0;
    			for (int j=1;j<=n;j++) if (i!=j) v.push_back(a[j]);
    			for (int j=1;j<(int)v.size();j+=2) cur=max(cur,v[j]-v[j-1]);
    			res=min(res,cur);
    		}
    		cout<<res<<'\n';
    	}
    }
}