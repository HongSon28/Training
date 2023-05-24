#include<bits/stdc++.h>
using namespace std;
int main() {
    string n;
    cin>>n;
    int m;
    for (int i=0;i<n.length();i++) {
        int x=n[i]-48;
        m+=x;
    }
    cout<<m;
}
