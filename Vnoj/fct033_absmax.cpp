#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long a[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cout<<max(abs(a[1]+a[2]),abs(a[n-1]+a[n]));
}
