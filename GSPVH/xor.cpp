#include<bits/stdc++.h>
using namespace std;
int t;
long long a,n,cur,mx;
int main() {
	freopen("xor.inp","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>a>>n;
    	cur=a;
    	mx=a;
    	if (a%n==0) {
    		cout<<0<<' ';
    		continue;
    	}
    	for (long long i=0;(1ll<<i)<=a*2;i++) {
    		if (a>>i&1) cur&=~(1ll<<i);
    		else mx|=(1ll<<i);
    		long long d1,d2;
    		d1=(cur+n-1)/n;
    		d2=mx/n;
    		//cout<<i<<' '<<cur<<' '<<mx<<' '<<d1<<' '<<d2<<endl;
    		if (d1<=d2) {
    			cout<<((d1*n)^a)<<' ';
    			break;
    		}
    	}
    }
}