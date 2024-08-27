#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int d[N+5];
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i) 
			for (int j=i*i;j<=N;j+=i)
				if (d[j]>i) d[j]=i;
	}
}
long long res=1;
int t,n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>t;
    while (t--) {
    	res=1;
    	cin>>n;
    	long long m=n;
    	while (n>1) {
    		int div=d[n];
    		long long fac=div;
    		while (n%div==0) {
    			n/=div;
    			fac*=div;
    		}
    		res*=(fac-1)/(div-1);
    	}
    	cout<<res-m<<'\n';
    }
}