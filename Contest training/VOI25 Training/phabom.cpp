#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
long long a[N+5],range[N+5],l[N+5],r[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i]>>range[i];
    	l[i]=r[i]=i;
    }
    for (int i=2;i<=n;i++) {
    	while (l[i]>1&&a[i]-a[l[i]-1]<=range[i]) {
    		range[i]=max(range[i],range[l[i-1]]-(a[i]-a[l[i]-1]));
    		l[i]=l[l[i]-1];
    	}
    }
    for (int i=n-1;i>=1;i--) {
    	while (r[i]<n&&a[r[i]+1]-a[i]<=range[i]) {
    		l[i]=min(l[i],l[r[i]+1]);
    		r[i]=r[r[i]+1];
    	}
    }
    for (int i=1;i<=n;i++) cout<<r[i]-l[i]+1<<' ';
}