#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5],c0,c1;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]%2==0) c0++;
		else c1++;
	}
	if (c1%2==1) {
		c0+=c1/2;
		if (c0%2==0) cout<<"YES";
		else cout<<"NO";
	} else cout<<"YES";
}