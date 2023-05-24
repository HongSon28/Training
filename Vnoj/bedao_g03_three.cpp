#include<bits/stdc++.h>
using namespace std;
bool check(long long n) {
    for (int i=2;i*i<=n;i++)
        if (n%i==0)
            return false;
    return true;
}
int main() {
    int m;
    cin>>m;
    while (m--) {
        long long n;
        cin>>n;
        if (n<=1) {
            cout<<0<<endl;
            continue;
        }
        long long sq=sqrt(n);
        if (sq*sq==n&&check(sq)) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
