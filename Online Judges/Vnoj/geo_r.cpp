#include<bits/stdc++.h>
using namespace std;
long long xa,ya,xb,yb,a,b,c,t1,t2;
int main() {
    cin>>xa>>ya>>xb>>yb>>a>>b>>c;
    t1=xa*a+ya*b+c;
    t2=xb*a+yb*a+c;
    if (t1*t2<0) cout<<"YES";
    else cout<<"NO";
}
