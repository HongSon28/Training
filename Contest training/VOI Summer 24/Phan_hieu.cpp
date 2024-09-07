#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n;
long long a[N+5],res=(long long)1e18;
void rec(int k,long long sum) {
	if (k==n+1) {
		res=min(res,abs(a[0]-sum-sum));
		return;
	}
	rec(k+1,sum+a[k]);
	rec(k+1,sum);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	a[0]+=a[i];
    }
    rec(1,0);
    cout<<res;
}