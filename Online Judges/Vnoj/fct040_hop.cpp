#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main() {
    cin>>n>>k;
    if (n%k==0) cout<<n/k;
    else cout<<n/k+1;
}
