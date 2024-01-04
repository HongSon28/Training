#include<bits/stdc++.h>
using namespace std;
long long n,res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	res=n;
	long long x=1;
	while (x<=n) {
		if (x*3<=n) res=min(res,n-x*3);
		res=min(res,n-x);
		x*=2;
	}
	cout<<res;
}