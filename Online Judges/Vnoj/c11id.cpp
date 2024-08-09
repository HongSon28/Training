#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long mod=1e9+7,res=1,a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
    	res*=a[i]-i+1;
    	res%=mod;
    }
    cout<<res;
}