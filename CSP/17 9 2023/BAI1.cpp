#include<bits/stdc++.h>
using namespace std;
int a,b,c,res;
int main() {
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a>>b>>c;
    for (int x=1;x*a<c;x++) {
        int t=c-x*a;
        if (t%b==0) {
            int y=t/b;
            if (__gcd(x,y)==1) res++;
        }
    }
    cout<<res;
}
