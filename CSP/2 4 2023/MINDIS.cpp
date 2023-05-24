#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long mid;
    if (n%2==1) mid=a[n/2];
    else mid=(a[n/2]+a[n/2-1])/2;
    long long sum=0;
    for (int i=0;i<n;i++) sum+=abs(mid-a[i]);
    cout<<sum;
}
