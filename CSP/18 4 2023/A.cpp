#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,res;
int main() {
    freopen("A.inp","r",stdin);
    freopen("A.out","w",stdout);
    cin>>n;
    for (int i=1;i*i<=n;i++)
        res+=(n/i)-i+1;
    cout<<res;
}
