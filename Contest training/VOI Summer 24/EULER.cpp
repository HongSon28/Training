#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n;
int phi[N+5];
void seive() {
	for (int i=1;i<=N;i++) phi[i]=i;
	for (int i=2;i<=N;i++) {
		if (phi[i]==i) {
			for (int j=i;j<=N;j+=i) phi[j]-=phi[j]/i;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    seive();
    while (t--) {
    	cin>>n;
    	cout<<phi[n]<<'\n';
    }
}