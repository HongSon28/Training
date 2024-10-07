#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int t,n;
long long c;
long long a[N+5];
long long res=0;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		long long odd=0,even=0;
		cin>>n>>c;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			if (a[i]%2) odd++;
			else even++;
		}
		res=(c+1)*(c+2)/2;
		res+=odd*(odd+1)/2+even*(even+1)/2;
		for (int i=1;i<=n;i++) {
			res-=a[i]/2+1;
			res-=c-a[i]+1;
		}
		cout<<res<<'\n';
	}
}