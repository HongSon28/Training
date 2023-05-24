#include<bits/stdc++.h>
using namespace std;
long long calc(long long x) {
    if (x==0) return 0;
    if (x==1) return 1;
    long long odd=((x+1)/2)*((x+1)/2);
    long long even=calc(x/2);
    return odd+even;
}
int main() {
    freopen("ODSUM.INP","r",stdin);
    freopen("ODSUM.OUT","w",stdout);
    int t;
    cin>>t;
    while (t--) {
        long long a,b;
        cin>>a>>b;
        a--;
        long long suma=calc(a),sumb=calc(b);
        cout<<sumb-suma<<endl;
    }
}
