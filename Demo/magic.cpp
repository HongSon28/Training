#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
int n,res;
long long t,a[N+5];
multiset<long long>s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>t;
    for (int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1;
    long long mx=a[1],mn=a[1];
    s.insert(a[1]);
    while (l<=n&&r<=n) {
    	while (r<n&&abs(a[r+1]-mx)<=t&&abs(a[r+1]-mn)<=t) {
    		s.insert(a[r+1]);
    		mx=max(mx,a[r+1]);
    		mn=min(mn,a[r+1]);
    		r++;
    	}
    	res=max(res,r-l+1);
    	s.erase(s.lower_bound(a[l]));
    	if (l==r) {
    		s.insert(a[l+1]);
    		r=l+1;
    	}
    	l++;
    	mn=*s.begin();
    	mx=*s.rbegin();
    }
    cout<<res;
}