#include<bits/stdc++.h>
using namespace std;
long long n;
int main() {
    cin>>n;
    long long res=n;
    res-=n/2+n/3+n/5+n/7;
    res+=n/6+n/10+n/14+n/15+n/35+n/21;
    res-=n/(2*3*5)+n/(3*5*7)+n/(2*5*7)+n/(2*3*7);
    res+=n/210;
    cout<<res;
}
