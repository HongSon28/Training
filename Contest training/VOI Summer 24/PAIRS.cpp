#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n;
long long m,res;
long long c[N+5];
int d[N+5];
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		for (int j=i*i;j<=N;j+=i*i)
			d[j]=j/(i*i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>n>>m;
    for (int i=1;i<=n;i++) c[d[i]]++;
    int r=n;
    for (int l=1;l<=n;l++) {
    	while (r>l&&1ll*l*r>m) {
    		c[d[r]]--;
    		r--;
    	}
    	if (l==r) break;
    	c[d[l]]--;
    	res+=c[d[l]];
    }
    cout<<res;
}