#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,k,cnt;
long long res;
bool p[N+5];
void seive() {
	memset(p,true,sizeof(p));
	p[0]=p[1]=false;
	for (int i=2;i*i<=N;i++) {
		if (p[i]) for (int j=i*i;j<=N;j+=i) p[j]=false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
	cin>>n>>k;
	for (int l=1,r=0;l<=n;l++) {
		while (cnt<k) {
			r++;
			if (r>n) break;
			cnt+=p[r];
		}
		if (r>n) break;
		res+=n-r+1;
		cnt-=p[l];
	}
	cout<<res;
}