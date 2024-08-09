#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("SOCHAN.INP","r",stdin);
    freopen("SOCHAN.OUT","w",stdout);
    int l,r;
    cin>>l>>r;
    if (l%2==1) l++;
    else l+=2;
    if (r%2==1) r--;
    else r-=2;
    cout<<(r-l)/2+1;
}
