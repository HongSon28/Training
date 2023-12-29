#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
long long a[N+5],k,res;
map<long long,long long>mp;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	res=0;
    	mp.clear();
    	cin>>n>>k;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    	}
    	for (int i=n;i>=1;i--) {
    		if (k<a[i]) continue;
    		res+=mp[((k-a[i])^a[i])];
    		mp[a[i]]++;
    	}
    	cout<<res<<'\n';
    }	
}