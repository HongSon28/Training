#include<bits/stdc++.h>
using namespace std;
bool check(long long s) {
    long long t=sqrt(s);
    if (t*t==s) return true;
    return false;
}
int main() {
    long long a,b,c;
    cin>>a>>b>>c;
    long long t=a*b/__gcd(a,b);
    long long bc=t*c/__gcd(t,c);
    long long sq=sqrt(bc);
    while ((sq*sq)%bc!=0) sq++;
    cout<<sq;
}
