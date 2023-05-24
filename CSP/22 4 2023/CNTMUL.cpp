#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll L,R,a,b;
    cin>>L>>R>>a>>b;
    ll c=a*b/__gcd(a,b);
    ll left,right;
    left=(L-1)/a;
    right=R/a;
    ll res=right-left;
    left=(L-1)/c;
    right=R/c;
    res-=right-left;
    cout<<res;
}
