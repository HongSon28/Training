#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
long long n,m;
long long p[N+5],f[N+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) p[i]=i;
	for (int i=2;i*i<=n;i++) {
		for (int j=i*i;j<=n;j+=i*i) p[j]=j/(i*i);
	}
	for (int i=1;i<=n;i++) f[p[i]]++;
	long long r=n;
	for (long long l=1;l<=r;l++) {
		while (l*r>m) {
			f[p[r]]--;
			r--;
		}
		if (l<=r) res+=f[p[l]]-1;
		f[p[l]]--;
	}
	cout<<res;
}