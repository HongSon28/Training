#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        long long sq=sqrt(n);
        if (sq*sq==n) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
}
