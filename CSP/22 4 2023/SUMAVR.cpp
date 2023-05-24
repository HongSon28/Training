#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int n;
    cin>>n;
    ll b[n];
    for (int i=0;i<n;i++) cin>>b[i];
    cout<<b[0]<<' ';
    ll sum=b[0];
    for (int i=1;i<n;i++) {
        ll a=b[i]*(i+1)-sum;
        cout<<a<<' ';
        sum+=a;
    }
}
