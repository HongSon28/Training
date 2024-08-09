#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,k;
int c[N+5];
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int t,i=1;i<=n;i++) {
    	cin>>t;
    	c[t%k]++;
    }
    for (int i=1;i*2<k;i++) {
    	res+=max(c[i],c[k-i]);
    }
    if (k%2==0) res+=(c[k/2]>0);
    res+=(c[0]>0);
    cout<<res;
}