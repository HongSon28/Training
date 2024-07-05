#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int t;
long long n;
long long s[N+5];
bool p[N+5];
void seive() {
	memset(p,true,sizeof(p));
	p[0]=p[1]=false;
	for (int i=2;i*i<=N;i++) {
		if (p[i]) {
			for (int j=i*i;j<=N;j+=i) p[j]=false;
		}
	}
	for (int i=1;i<=N;i++) s[i]=s[i-1]+p[i];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>t;
    while (t--) {
    	cin>>n;
    	long long res=0;
    	for (int i=1;i<=n;i++) {
    		long long t1=s[i+n]-s[i];
    		long long t2=n-t1;
    		if (i==1) t1--;
    		else t2--;
    		res+=t1*t2;
    	}
    	cout<<n*(n-1)*(n-2)/6-res/2<<'\n';
    }
}