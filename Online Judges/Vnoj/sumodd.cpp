#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned l,r;
    cin>>l>>r;
    long long tong=0;
    for (unsigned i=l;i<=r;i++) {
        if (i%2==1)
            tong+=i;
    }
    cout<<tong;
}
