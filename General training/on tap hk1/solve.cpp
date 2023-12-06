#include<bits/stdc++.h>
using namespace std;
bool check(long long a, long long b) {
    long long c=0;
    while (a!=0) {
        c+=a%10;
        a/=10;
    }
    if (b==c)
        return true;
    return false;
}
int main() {
    long long n;
    cin>>n;
    for (int i=0;i<=90;i++) {
        long long s=i*i+4*n;
        long long sq=sqrt(s);
        if (sq*sq==s&&check((sq-i)/2,i)==true) {
            cout<<(sq-i)/2;
            return 0;
        }
    }
    cout<<-1;
}
