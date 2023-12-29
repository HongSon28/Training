#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,x,mx,res;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>x;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=n;i++) {
		int diff=mx-a[i];
		if (diff%x!=0) {
			cout<<-1;
			return 0;
		}
		res+=diff/x;
	}
	cout<<res;
}