#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n,a,b;
    cin>>n>>a>>b;
    ll t=abs(a-b);
    cout<<min(t,n-t);
}
