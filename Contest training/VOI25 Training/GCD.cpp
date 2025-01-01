#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n;
int phi[N+5];
long long sum[N+5],res;
vector<int>v;
void seive() {
	for (int i=0;i<=n;i++) phi[i]=i;
	for (int i=2;i<=n;i++) {
		if (phi[i]==i) {
			v.push_back(i);
			for (int j=i;j<=n;j+=i) phi[j]-=phi[j]/i;
		}
		phi[i]*=2;
	}
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+phi[i];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    seive();
    for (auto p:v) {
    	res+=sum[n/p];
    	//cout<<p<<' '<<n/p<<' '<<sum[n/p]<<endl;
    }
    cout<<res;
}