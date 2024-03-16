#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5],sum,cur;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum+=a[i];
    }
    cin>>q;
    while (q--) {
    	int type;
    	cin>>type;
    	if (type==1) {
    		long long i,x;
    		cin>>i>>x;
    		i-=cur;
    		i=(i%n+n)%n;
    		if (i==0) i=n;
    		sum+=x-a[i];
    		//cout<<cur<<' '<<i<<' '<<a[i]<<' '<<x-a[i]<<endl;
    		a[i]=x;
    		cout<<sum<<'\n';
    	} else {
    		int k;
    		cin>>k;
    		cur+=k;
    		cur%=n;
    	}
    }
}