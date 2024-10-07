#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t;
int n,k;
int x[N+5],y[N+5];
int l[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>n>>k;
    	for (int i=1;i<=n;i++) cin>>x[i];
    	for (int i=1;i<=n;i++) cin>>y[i];
    	sort(x+1,x+1+n);
    	for (int i=1;i<=n;i++) {
    		int lo=i+1,hi=n;
    		l[i]=i;
    		while (lo<=hi) {
    			int mid=(lo+hi)/2;
    			if (x[mid]-x[i]<=k) {
    				l[i]=mid;
    				lo=mid+1;
    			} else hi=mid-1;
    		}
    		l[i]=l[i]-i+1;
    	}
    	int res=0;
    	l[n+1]=0;
    	for (int i=n;i>=1;i--) {
    		l[i]=max(l[i],l[i+1]);
    		int lo=1,hi=i-1,pos=i;
    		while (lo<=hi) {
    			int mid=(lo+hi)/2;
    			if (x[i]-x[mid]<=k) {
    				pos=mid;
    				hi=mid-1;
    			} else lo=mid+1;
    		}
    		res=max(res,i-pos+1+l[i+1]);
    	}
    	cout<<res<<'\n';
    }	
}