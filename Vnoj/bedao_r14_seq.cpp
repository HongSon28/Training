#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    if (n==1) cout<<1;
    else if (n==2) cout<<1<<' '<<2;
    else if (n==3) cout<<1<<' '<<3<<' '<<5;
    else for (int i=1;i<=n;i++) cout<<n+i<<' ';
}
