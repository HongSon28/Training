#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	a[1]=a[2]=a[3]=1;
	cin>>n;
	for (int i=4;i<=n;i++) a[i]=a[i-1]+a[i-3];
	cout<<a[n];
}