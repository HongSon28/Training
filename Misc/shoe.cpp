#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int tong=0;
    int tong2;
    if (n>m) {
        tong+=m;
        n-=m;
        tong2=n/2;
    } else if (n<m) {
        tong+=n;
        m-=n;
        tong2=m/2;
    } else {
        tong+=n;
        tong2=0;
    }
    cout<<tong<<" "<<tong2;
}

