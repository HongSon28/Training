#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N+5],res,last;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    res=last=a[1];
    for (int i=2;i<=n;i++) {
    	if (a[i]>last) res+=a[i]-last;
    	last=a[i];
    }
    cout<<res;
}