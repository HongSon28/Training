#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int d[N+5];
int t,a,b;
void seive() {
	iota(d,d+N+5,0);
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i) 
			for (int j=i*i;j<=N;j+=i) 
				if (d[j]>i) 
					d[j]=i;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>t;
    while (t--) {
    	cin>>a>>b;
    	int g=__gcd(a,b);
    	a/=g,b/=g;
    	int c1=0,c2=0;
    	while (a>1) {
    		int div=d[a];
    		while (a%div==0) {
    			a/=div;
    			c1++;
    		}
    	}
    	while (b>1) {
    		int div=d[b];
    		while (b%div==0) {
    			b/=div;
    			c2++;
    		}
    	}
    	cout<<max(c1,c2)<<'\n';
    }
}