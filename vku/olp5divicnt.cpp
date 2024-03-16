#include<bits/stdc++.h>
using namespace std;
const int N=4e6;
long long n,a,b,res;
long long d[N+5];
bool p[N+5];
long long f[N+5];
void seive() {
	memset(p,true,sizeof(p));
	for (int i=1;i<=N;i++) f[i]=1;
	p[0]=p[1]=false;
	for (long long i=2;i*i<=N;i++) {
		if (p[i]) {
			for (long long j=i*i;j<=N;j+=i) p[j]=false;
		}
	}
	for (long long i=1;i<=N;i++) {
		for (long long j=i;j<=N;j+=i) {
			d[j]++;
			if (p[i]) f[j]*=i;
		}
	}
}
int main() {
	seive();
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>a>>b;
    for (long long i=1;i<=N;i++) {
    	//cout<<i<<' '<<d[i]<<' '<<f[i]<<endl;
    	if (d[i]>=a&&d[i]<=b) {
    		if (i<=n&&f[i]<=n&&i*f[i]<=n) res++;
    	}
    }
    cout<<res;
}