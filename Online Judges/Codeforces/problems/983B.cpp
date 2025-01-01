#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,q;
int a[N+5];
int f[N+5][N+5],mx[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	f[1][i]=mx[1][i]=a[i];
    }	
    for (int i=2;i<=n;i++) {
    	for (int j=1;j<=n-i+1;j++) {
    		f[i][j]=(f[i-1][j]^f[i-1][j+1]);
    		mx[i][j]=max({f[i][j],mx[i-1][j],mx[i-1][j+1]});
    	}
    }
    cin>>q;
    while (q--) {
    	int l,r;
    	cin>>l>>r;
    	cout<<mx[r-l+1][l]<<'\n';
    }
}