#include<bits/stdc++.h>
using namespace std;
int x,y,res;
int main() {
    cin>>x>>y;
    int t=__gcd(x,y);
    for (int i=1;i*i<=t;i++) {
        if (t%i==0) {
            int j=t/i;
            if (i!=j) res+=2;
            else res++;
        }
    }
    cout<<res;
}
