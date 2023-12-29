#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	int c0=0,c1=0,fi=n+1;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		if (a[i]<0) {
    			c0++;
    			fi=min(fi,i);
    		} else if (a[i]==0) c1++;
    	}
    	if (c1>0) cout<<0<<'\n';
    	else if (c0%2==1) cout<<0<<'\n';
    	else if (c0%2==0&&c0>0) cout<<1<<'\n'<<fi<<' '<<0<<'\n';
    	else cout<<1<<'\n'<<1<<' '<<0<<'\n';
    }
}