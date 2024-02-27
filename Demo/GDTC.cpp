#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n;
int a[N+5];
long long l[N+5],r[N+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	l[i]=i;
    	long long cnt=0;
    	for (long long j=i-1;j>=1;j--) {
    		if (a[j]<a[i]) cnt++;
    		l[i]=min(l[i],j+cnt);
    	}
    	r[i]=i;
    	cnt=0;
    	for (long long j=i+1;j<=n;j++) {
    		if (a[j]>a[i]) cnt++;
    		r[i]=max(r[i],j-cnt);
    	}
    	//cout<<l[i]<<' '<<r[i]<<endl;
    }
    for (int i=1;i<=n;i++) {
    	for (int j=i+1;j<=n;j++) {
    		res+=max({j-l[i],r[j]-i,llabs(a[i]-a[j])});
    		//cout<<i<<' '<<j<<' '<<j-l[i]<<' '<<r[j]-i<<endl;
    	}
    }
    cout<<res;
}