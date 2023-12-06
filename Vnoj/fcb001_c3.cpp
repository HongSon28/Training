#include<bits/stdc++.h>
using namespace std;
const int N=500000;
int n,k,a;
long long c[N+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a;
    	c[a]++;
    	if (k-a*a>0&&k-a*a<=500) res+=c[k-a*a];
    }	
    cout<<res;
}