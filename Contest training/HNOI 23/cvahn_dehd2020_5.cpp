#include<bits/stdc++.h>
using namespace std;
int n,u,v;
string s;
int main() {
    cin>>n>>u>>v;
    cin>>s;
    for (auto i:s) {
        if (i=='U') {
            u++;
            if (u>n) u-=n;
        } else if (i=='D') {
            u--;
            if (u<1) u+=n;
        } else if (i=='L') {
            v++;
            if (v>n) v-=n;
        } else {
            v--;
            if (v<1) v+=n;
        }
    }
    cout<<(u-1)*n+v;
}
