#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int a[N+5];
int tryinc() {
	int pos=n+1;
	for (int i=2;i<=n;i++) {
		if (a[i]<a[i-1]) {
			pos=i;
			break;
		}
	}
	if (pos==n+1) return 0;
	if (a[n]>a[1]) return -1;
	for (int i=pos+1;i<=n;i++) {
		if (a[i]<a[i-1]) return -1;
	}
	return min(n-pos+1,pos+1);
}
int trydec() {
	int pos=n+1;
	for (int i=2;i<=n;i++) {
		if (a[i]>a[i-1]) {
			pos=i;
			break;
		}
	}
	if (pos==n+1) return 1;
	if (a[n]<a[1]) return -1;
	for (int i=pos+1;i<=n;i++) {
		if (a[i]>a[i-1]) return -1;
	}
	return min(n-pos+2,pos);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	int res=-1;
    	if (tryinc()!=-1) res=tryinc();
    	if (trydec()!=-1) {
    		if (res==-1) res=trydec();
    		else res=min(res,trydec());
    	} 
    	cout<<res<<'\n';
    }
}