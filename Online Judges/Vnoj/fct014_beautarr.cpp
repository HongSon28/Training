#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,a[N+5],c[N+5];
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int r=0;
    for (int l=1;l<=n;l++) {
    	while (r<n&&c[a[r+1]]<=1) {
    		c[a[r+1]]++;
    		r++;
    	}
    	res+=r-l+1;
    	c[a[l]]--;
    }
    cout<<res;
}