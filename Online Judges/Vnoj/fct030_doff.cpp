#include<bits/stdc++.h>
using namespace std;
int n;
int a,b;
int main() {
    cin>>n;
    a=n/7;
    b=n%7;
    if (b<=2) cout<<a*2<<' '<<a*2+b;
    else if (b>=5) cout<<a*2+b-5<<' '<<a*2+2;
    else cout<<a*2<<' '<<a*2+2;
}
