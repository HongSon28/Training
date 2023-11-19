#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin>>n;
    for (int i=0;i<32;i++) {
        if (((n>>i)&1)==1) cout<<(1<<i)<<' ';
    }
}
