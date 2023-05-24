#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    n%=4;
    if (n==1) cout<<3;
    else if (n==2) cout<<5;
    else if (n==3) cout<<9;
    else cout<<7;
}
