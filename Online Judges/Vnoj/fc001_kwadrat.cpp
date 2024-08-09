#include<bits/stdc++.h>
using namespace std;
long long n,res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    res=n;
    for (long long i=2;i*i<=n;i++) {
    	int cnt=0;
    	while (n%i==0) {
    		n/=i;
    		cnt++;
    	}
    	if (cnt%2==1) res*=i;
    }	
    if (n!=1) res*=n;
    cout<<res;
}