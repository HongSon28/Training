#include<bits/stdc++.h>
using namespace std;
int t;
int va,vb,vong,s;
int main() {
    cin>>t;
    while (t--) {
        cin>>va>>vb>>vong>>s;
        cout<<s*vong/(va+vb)<<endl;
    }
}
