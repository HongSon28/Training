#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,s;
int res;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>s;
    res=n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int pos=1,lo=2,hi=n;
    while (lo<=hi) {
    	int mid=(lo+hi)/2;
    	if (a[1]+a[mid]<=s) {
    		pos=mid;
    		lo=mid+1;
    	} else hi=mid-1;
    }
    for (int i=1;i<=pos;i++) {
    	while (i<=pos&&a[i]+a[pos]>s) pos--;
    	if (pos>i) {
    		res--;
    		pos--;
    	}
    }
    cout<<res;
}