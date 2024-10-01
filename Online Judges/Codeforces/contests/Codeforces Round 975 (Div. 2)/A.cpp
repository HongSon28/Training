#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n;
int a[N+5];
int get(int l,int r) {
	int len=r-l+1;
	return (len+1)/2;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	int res=0;
    	for (int i=1;i<=n;i++) {
    		int cur=a[i]+1;
    		cur+=get(1,i-2);
    		cur+=get(i+2,n);
    		res=max(res,cur);
    	}
    	cout<<res<<'\n';
    }
}