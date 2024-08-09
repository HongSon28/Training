#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool p[N+5];
void seive() {
	memset(p,true,sizeof(p));
	p[0]=p[1]=false;
	for (long long i=2;i*i<=N;i++) {
		if (p[i]) {
			for (long long j=i*i;j<=N;j+=i) p[j]=false;
		}
	}
}
bool check(long long x) {
	for (long long i=2;i*i<=x;i++) {
		if (x%i==0) return false;
	}
	return true;
}
long long n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>n;
    for (long long i=2;i*i*i<=n;i++) {
    	if (!p[i]) continue;
    	long long cur=i*i,cnt=2;
    	while (cur<n) {
    		cur*=i;
    		cnt++;
    	}
    	if (cur==n) {
    		cout<<i<<' '<<cnt;
    		return 0;
    	}
    }
    long long sq=sqrt(n);
    if (sq*sq==n&&check(sq)) cout<<sq<<' '<<2;
    else cout<<0;
}