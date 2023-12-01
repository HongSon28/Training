#include<bits/stdc++.h>
using namespace std;
long long n,res=LLONG_MAX;
int main() {
	cin>>n;
	for (long long i=1;i*i<=n;i++) {
		if (n%i!=0) continue;
		long long j=n/i;
		res=min(res,i+j-2);
	}
	cout<<res;
}
