#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    char c[n];
    for (int i=0;i<n;i++) {
        cin>>c[i];
    }
    int same=1;
    int res=0;
    for (int i=1;i<n;i++) {
        if (c[i]==c[i-1]) {
            same++;
        } else {
            res+=same/2;
            same=1;
        }
    }
    res+=same/2;
    cout<<res;
}
