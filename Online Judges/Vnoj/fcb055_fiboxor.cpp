#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b,n;
    cin>>a>>b>>n;
    if (n%3==0) cout<<a;
    else if (n%3==1) cout<<b;
    else cout<<(a^b);
}
