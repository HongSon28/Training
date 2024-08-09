#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int a[N+5],c[N+5];
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	a[0]=INT_MAX;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		c[a[i]]++;
	}
	for (int i=1;i<=n;i++) {
		if (c[a[i]]==1&&a[res]>a[i]) res=i;
	}
	if (res==0) cout<<-1;
	else cout<<res;
}