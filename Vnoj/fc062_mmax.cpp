#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cout<<max({a[1]*a[2],a[n]*a[n-1],a[1]*a[2]*a[3],a[1]*a[2]*a[n],a[1]*a[n-1]*a[n],a[n-2]*a[n-1]*a[n]});	
}