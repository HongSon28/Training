#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main() {
    long unsigned int a,b;
    cin>>a>>b;
    cout<<__gcd(a,b)<<" "<<(a*b)/__gcd(a,b);
}
