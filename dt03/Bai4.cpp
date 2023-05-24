#include<bits/stdc++.h>
using namespace std;
long long a[100001];
long long n,x;
int main() {
    ifstream inp("gifts.inp");
    ofstream out("gifts.out");
    inp>>n>>x;
    for (int i=0;i<n;i++)
        inp>>a[i];

    sort(a,a+n);
    long l=0,r=n-1;
    long long mx=0;
    if (a[l]+a[r]<=x)
        mx=a[l]+a[r];
    while (l+1<r) {
        if (a[l]+a[r]<=x) {
            l++;
        } else {
            r--;
        }
        if (a[l]+a[r]<=x) {
            mx=max(mx,a[l]+a[r]);
        }
    }
    out<<mx;
}
