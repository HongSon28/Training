#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int g;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	g=a[1];
	for (int i=2;i<=n;i++) g=__gcd(g,a[i]);
	if (g==1) cout<<0;
	else cout<<-1;
}