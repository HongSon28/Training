#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
ll t;
ll x,y,a;
int main() {
    cin>>t;
    while (t--) {
        cin>>x>>y>>a;
        ll temp=a/(x+y);
        cout<<temp<<endl;
        cout<<5*min(temp*x+a-temp*(x+y),a)<<endl;
    }
}
