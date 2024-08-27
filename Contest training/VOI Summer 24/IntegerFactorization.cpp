#include<bits/stdc++.h>
using namespace std;
long long x;
int cnt;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    while (cin>>x) {
    	if (x==0) return 0;
    	for (long long i=2;i*i<=x;i++) {
    		cnt=0;
    		while (x%i==0) {
    			x/=i;
    			cnt++;
    		}
    		if (cnt!=0) cout<<i<<'^'<<cnt<<' ';
    	}
    	if (x!=1) cout<<x<<"^1";
    	cout<<'\n';
    }
}