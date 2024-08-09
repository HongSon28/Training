#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q,l,r;
long long a[N+5],sum[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    }
    while (q--) {
    	cin>>l>>r;
    	cout<<sum[r]-sum[l-1]<<'\n';
    }
}