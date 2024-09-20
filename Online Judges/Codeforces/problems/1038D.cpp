#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
long long a[N+5];
long long mn=2e9,sum;
bool cpos,cneg;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n==1) {
    	cout<<a[1];
    	return 0;
    }	
    for (int i=1;i<=n;i++) {
    	sum+=abs(a[i]);
    	mn=min(mn,abs(a[i]));
    	cpos|=(a[i]>=0);
    	cneg|=(a[i]<=0);
    }
    if (cpos&&cneg) cout<<sum;
    else cout<<sum-2*mn;
}