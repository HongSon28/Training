#include<bits/stdc++.h>
using namespace std;
bool check(long long n) {
    if (n<2) return false;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) return false;
    }
    return true;
}
int main() {
    long long n;
    cin>>n;
    long long s=sqrt(n);
    while (true) {
        if (check(s)==true&&s*s>=n){
            cout<<s*s;
            return 0;
        }
        s++;
    }
}
