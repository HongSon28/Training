#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("Demboi.inp");
    ofstream out("Demboi.out");
    int t;
    inp>>t;
    int kq[t];
    for (int i=0;i<t;i++) {
        int a,b,l,r;
        cin>>l>>r>>a>>b;
        int bcnn=a*b/__gcd(a,b);
        l--;
        int tong=(r/a)-(l/a)+(r/b)-(l/b)-(r/bcnn)+(l/bcnn);
        kq[i]=tong;
    }
    for (int i=0;i<t;i++) {
        out<<kq[i]<<endl;
    }
}
