#include<bits/stdc++.h>
using namespace std;
long long n,sq;
bool check(long long x) {
    for (int i=2;i*i<=x;i++)
        if (x%i==0) return false;
    return true;
}
int main() {
    cin>>n;
    sq=sqrt(n);
    while (true) {
        if (sq*sq>=n&&check(sq)) {
            cout<<sq*sq;
            break;
        }
        sq++;
    }
}
