#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
bool p[N+5];
int pr[N+5],d[N+5];
int pos;
void seive() {
	memset(p,true,sizeof(p));
	for (int i=4;i<=N;i+=2) p[i]=false;
	for (int i=3;i*i<=N;i+=2) {
		if (p[i])
			for (int j=i*i;j<=N;j+=i) p[j]=false;
	}
	pr[++pos]=2;
	for (int i=3;i<=N;i+=2)
		if (p[i])
			pr[++pos]=i;
}
int t;
long long n,m,cur,temp,res=1;
int cnt;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>t;
    while (t--) {
    	res=1;
    	cin>>n;
    	m=n;
    	for (int i=1;i<=pos;i++) {
    		if (pr[i]*pr[i]>n) break;
    		if (n%pr[i]==0) {
    			long long fac=pr[i];
    			while (n%pr[i]==0) {
    				n/=pr[i];
    				fac*=pr[i];
    			}
    			res*=(fac-1)/(pr[i]-1);
    		}
    	}
    	if (n>1) res*=n+1;
    	cout<<res-m<<'\n';
    }
}