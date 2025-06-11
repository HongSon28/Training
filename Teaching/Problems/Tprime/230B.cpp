#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
bool check(long long n) {
	for (int i=2;i*i<=n;i++)
		if (n%i==0) return false;
	return true;
}
int main() {
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n;
		long long sq=sqrt(n);
		if (sq*sq==n&&n!=1&&check(sq)) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}
