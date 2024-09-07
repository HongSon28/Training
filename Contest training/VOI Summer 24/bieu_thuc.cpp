#include<bits/stdc++.h>
using namespace std;
const int N=10;
int t,n;
long long m,a[N+5];
int sgn[N+5];
int res;
stack<long long>st;
bool check() {
	long long sum=0;
	st.push(a[1]);
	for (int i=2;i<=n;i++) {
		if (sgn[i]==1) st.push(a[i]);
		else if (sgn[i]==2) st.push(-a[i]);
		else {
			long long t=st.top();
			st.pop();
			st.push(t*a[i]%m);
		}
	}
	while (!st.empty()) {
		sum+=st.top();
		st.pop();
	}
	return (sum%m==0);
}
void rec(int k) {
	if (k==n+1) {
		res+=check();
		return;
	}
	for (int i=1;i<=3;i++) {
		sgn[k]=i;
		rec(k+1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	res=0;
    	cin>>n>>m;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		a[i]%=m;
    	}
    	rec(2);
    	cout<<res<<'\n';
    }
}