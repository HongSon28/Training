#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,del;
long long a[N+5];
vector<long long>b(N+5,INT_MAX);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("RIGHT.INP","r",stdin);
    freopen("RIGHT.OUT","w",stdout);
	b[0]=INT_MIN;
	cin>>n>>del;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		long long k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		b[k]=a[i];
		cout<<k*del+a[i]<<'\n';
	}
}