#include<bits/stdc++.h>
using namespace std;
int main() {
    //freopen("LARES.INP","r",stdin);
    //freopen("LARES.OUT","w",stdout);
    long long m,n,k;
    cin>>m>>n>>k;
    long long g=min(m/2,n);
    if (k>n-g) k-=n-g;
    else k=0;
    if (k>m-g*2) k-=m-g*2;
    else k=0;
    if (k==0) cout<<g;
    else {
        g-=k/3;
        if (k%3!=0) g--;
        if (g<0) cout<<0;
        else cout<<g;
    }
}
