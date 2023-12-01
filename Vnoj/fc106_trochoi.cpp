#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<long long>());
	for (int i=1;i<=n;i++) {
		if (i%2==1) res+=a[i];
		else res-=a[i];
	}	
	cout<<res;
}