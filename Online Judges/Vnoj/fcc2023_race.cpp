#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long n,cur;
long long f[N+5],c[N+5],res;
int a[N+5];
bool comp(int a,int b) {
	return c[a]<c[b];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>f[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    iota(a,a+1+n,0);
    sort(a+1,a+1+n,comp);
    for (int i=1;i<=n;i++) {
    	long long temp=min(n-cur,f[a[i]]);
    	if (temp>0) {
    		cur+=temp;
    		res+=temp*c[a[i]];
    	}
    }
    if (cur==n) cout<<res;
    else cout<<-1;
}