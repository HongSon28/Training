#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
int c1,c2,c3;
int main() {
    freopen("TBS.INP","r",stdin);
    freopen("TBS.OUT","w",stdout);
    cin>>a>>b>>c>>d;
    if (a<0) c1++;
    else if (a>0) c2++;
    else c3++;
    if (b<0) c1++;
    else if (b>0) c2++;
    else c3++;
    if (c<0) c1++;
    else if (c>0) c2++;
    else c3++;
    if (d<0) c1++;
    else if (d>0) c2++;
    else c3++;
    if (c3>0) cout<<0;
    else if (c1%2==0) cout<<1;
    else cout<<-1;
}
