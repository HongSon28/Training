#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,m;
long long a[N+5],b[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>m;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	for (int i=1;i<=m;i++) cin>>b[i];
    	sort(a+1,a+1+n);
    	sort(b+1,b+1+m,greater<long long>());
    	long long res=0;
    	for (int i=1;i<=n;i++) {
    		if (llabs(a[i]-b[i])<=a[i]-b[m-(n-i+1)+1]) {
    			for (int j=i;j<=n;j++) res+=a[j]-b[m-(n-j+1)+1];
    			break;
    		}
    		res+=llabs(a[i]-b[i]);
    	}
    	cout<<res<<'\n';
    }
}