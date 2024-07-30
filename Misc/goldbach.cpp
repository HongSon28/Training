#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool p[N+5];
vector<int>pr;
void seive() {
	memset(p,true,sizeof(p));
	for (int i=2;i*i<=N;i++) {
		if (p[i]) {
			for (int j=i*i;j<=N;j+=i) p[j]=false;
		}
	}
	for (int i=2;i<=N;i++) 
		if (p[i]) pr.push_back(i);
}
bool check(long long k) {
	for (long long i=2;i*i<=k;i++) {
		if (k%i==0) return false;
	}
	return true;
}
int t;
long long n;
int main() {
	seive();
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	assert(n<=N);
    	for (auto i:pr) {
    		if (n-i<=N) {
    			if (p[n-i]) {
    				cout<<i<<' '<<n-i<<'\n';
    				break;
    			}
    		} else if (check(n-i)) {
    			cout<<i<<' '<<n-i<<'\n';
    			break;
    		}
    	}
    }
}