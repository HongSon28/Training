#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int t,n,v;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>v;
		a[1][1]=v;
		cout<<v<<'\n';
		for (int i=2;i<=n;i++) {
			for (int j=1;j<=i;j++) {
				a[i][j]=a[i-1][j-1]-a[i][j-1];
				cout<<a[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
}