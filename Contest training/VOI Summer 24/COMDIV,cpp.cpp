#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,a,b;
int c[N+5];
void seive() {
	for (int i=1;i<=N;i++) {
		for (int j=i;j<=N;j+=i) c[j]++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    seive();
    while (t--) {
    	cin>>a>>b;
    	cout<<c[__gcd(a,b)]<<'\n';
    }
}