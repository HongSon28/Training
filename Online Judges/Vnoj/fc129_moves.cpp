#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,q;
long long d,cur,a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>q;
    while (q--) {
    	cin>>n>>d;
    	long long sum=0;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		sum+=a[i];
    	}
    	long long x=d*((n+1)/2);
    	if (sum<=x) cout<<"YES"<<'\n';
    	else cout<<"NO"<<'\n';
    }
}