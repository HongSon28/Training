#include<bits/stdc++.h>
using namespace std;
int main() {
    //freopen("ROTATE.INP","r",stdin);
    //freopen("ROTATE.OUT","w",stdout);
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double mx=a/c-b/d;
    int spin=0;
    for (int i=1;i<=3;i++) {
        double t=a;
        a=c;
        c=d;
        d=b;
        b=t;
        t=a/c-b/d;
        if (t>mx) {
            mx=t;
            spin=i;
        }
    }
    cout<<spin;
}
