#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
int a[N+5];
int l[N+5],r[N+5];
int mn[N+5],mx[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		a[i]--;
    	}
    	for (int i=1;i<=n;i++) l[i]=min(l[i-1],a[i]-i+1);
    	mn[n+1]=0;
    	for (int i=n;i>=1;i--) r[i]=min(r[i+1],a[i]-(n-i));
    	int res=n;
    	for (int i=1;i<=n;i++) {
    		if (l[i-1]<=0||r[i+1]<=0) {
    			res--;
    			continue;
    		}
    		
    	}
    }	
}