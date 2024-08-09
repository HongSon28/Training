#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b;
unsigned long long N=1e6,M=1e9;
int main() {
    freopen("DIENPHEPTINH.INP","r",stdin);
    freopen("DIENPHEPTINH.OUT","w",stdout);
    cin>>a>>b;
    if (a*3==b) cout<<'+'<<'\n'<<'+';
    else if (a==b) cout<<'+'<<'\n'<<'-';
    else if (a<=N&&a*a*a==b) cout<<'*'<<'\n'<<'*';
    else if (a<=M&&a*(a-1)==b) cout<<'*'<<'\n'<<'-';
    else if (a<=M&&a*(a+1)==b) cout<<'*'<<'\n'<<'+';
}
