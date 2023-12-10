#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,x;
int a[N+5];
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int l=0;
    for (int r=2;r<=n;r++) {
    	if (l==r-2&a[r-1]+a[r]<=x) l++;
    	else while (l>0&&a[l]+a[r]>x) l--;
    	res+=l;
    }
    cout<<res;
}