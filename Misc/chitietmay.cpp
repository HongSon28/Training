#include<bits/stdc++.h>
using namespace std;
int main() {
    int s,k,m,res=0;
    cin>>s>>k>>m;
    int n=k-m;
    long long phoi=s/k;
    while (phoi!=0) {
        long long temp=phoi*m;
        res+=phoi*(k/m);
        s-=temp*(k/m);
        phoi=s/k;
    }
    cout<<res;
}
