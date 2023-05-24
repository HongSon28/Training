#include<bits/stdc++.h>
using namespace std;
int main() {
    long long m,n,k,a,b;
    cin>>m>>n>>k;
    if (m>n) swap(m,n);
    if (k%2==0) {
        a=k/2;
        b=k/2;
        if (a>m-1) {
            a=m-1;
            b=k-a;
        }
    } else {
        a=k/2;
        b=k/2+1;
        if (a>m-1) {
            a=m-1;
            b=k-a;
        }
    }
    cout<<min(m*n,(a+1)*(b+1));
}
