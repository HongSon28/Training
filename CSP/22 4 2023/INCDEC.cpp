#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll a,b;
    cin>>a>>b;
    ll dif=abs(a-b);
    ll ans=ceil((float)dif/10);
    cout<<ans;
}
