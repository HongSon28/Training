#include<bits/stdc++.h>
using namespace std;
int t;
int n,x,y;
int main() {
    cin>>t;
    while (t--) {
        cin>>n>>x>>y;
        int g=__gcd(x,y);
        x/=g;
        y/=g;
        int temp=n/(x+y);
        x*=temp;
        y*=temp;
        if (x>y) swap(x,y);
        cout<<x<<' '<<y<<endl;
    }
}
