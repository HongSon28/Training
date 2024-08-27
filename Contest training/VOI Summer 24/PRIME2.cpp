#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
bool p[N+5];
long long sum[N+5],cnt[N+5];
void seive() {
	memset(p,true,sizeof(p));
	p[0]=p[1]=false;
	for (int i=4;i<=N;i+=2) p[i]=false;
	for (int i=3;i*i<=N;i+=2) {
		if (p[i])
			for (int j=i*i;j<=N;j+=i) p[j]=false;
	}
	for (int i=1;i<=N;i++) {
		sum[i]=sum[i-1];
		cnt[i]=cnt[i-1];
		if (p[i]) {
			sum[i]+=i;
			cnt[i]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    int t,l,r;
    cin>>t;
    cout.precision(2);
    while (t--) {
    	cin>>l>>r;
    	double res=(double)(sum[r]-sum[l-1])/(double)(cnt[r]-cnt[l-1]);
    	cout<<fixed<<res<<'\n';
    }	
}