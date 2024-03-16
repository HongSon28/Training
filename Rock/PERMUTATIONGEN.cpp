#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
int a[N+5];
bool check() {
	for (int i=1;i<=n;i++) {
		if (a[i]!=n-i+1) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (check()) {
		cout<<-1;
		return 0;
	}
	next_permutation(a+1,a+1+n);
	for (int i=1;i<=n;i++) cout<<a[i]<<' ';
}