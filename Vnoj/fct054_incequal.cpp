#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,x,res,mx;
int a[N+5];
int main() {
	cin>>n>>x;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=n;i++) {
		int dif=mx-a[i];
		if (dif%x!=0) {
			cout<<-1;
			return 0;
		}
		res+=dif/x;
	}
	cout<<res;
}