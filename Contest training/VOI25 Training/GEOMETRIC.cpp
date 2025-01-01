#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t;
long long n;
long long a[N+5];
long long mod=1e9+22071997;
void add(long long &x,long long y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int main() {
	freopen("GEOMETRIC.INP","r",stdin);
	freopen("GEOMETRIC.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	long long res=0;
    	cin>>n;
    	for (int i=1;i<=n/2;i++) {
    		a[1]=i;
    		for (int j=a[1]+1;j+a[1]<=n;j++) {
    			a[2]=j;
    			long long sum=a[1]+a[2];
    			if (sum==n) {
    				add(res,1);
    				continue;
    			}
    			for (int k=3;k<=n;k++) {
    				if ((a[k-1]*a[k-1])%a[k-2]!=0) break;
    				a[k]=a[k-1]*a[k-1]/a[k-2];
    				sum+=a[k];
    				if (sum==n) {
    					add(res,1);
    					break;
    				} else if (sum>n) break;
    			}
    		}
    	}
    	cout<<res<<' ';
    }
}