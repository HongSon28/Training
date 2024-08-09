#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long h[N+5],res;
long long l[N+5],r[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) l[i]=max(l[i-1],h[i]);
    for (int i=n;i>=1;i--) r[i]=max(r[i+1],h[i]);
    for (int i=1;i<=n;i++) {
    	res+=max(0ll,min(l[i-1],r[i+1])-h[i]);
    }
    cout<<res;
}