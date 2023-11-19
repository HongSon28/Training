#include<bits/stdc++.h>
using namespace std;
int xa,ya,xc,yc,xm,ym,xn,yN,res;
int main() {
    cin>>xa>>ya>>xc>>yc>>xm>>ym>>xn>>yN;
    if (xa>xc) swap(xa,xc);
    if (ya>yc) swap(ya,yc);
    if (xa<xm&&xm<xc&&ya<ym&&ym<yc) res++;
    if (xa<xn&&xn<xc&&ya<yN&&yN<yc) res++;
    cout<<res;
}
