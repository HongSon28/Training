#include<bits/stdc++.h>
using namespace std;
long long t,n,sum,c0,c1,c2,cnt;
int main() {
    cin>>n;
    t=n;
    while (t>0) {
        sum+=t%10;
        if ((t%10)%3==0) c0++;
        else if ((t%10)%3==1) c1++;
        else c2++;
        cnt++;
        t/=10;
    }
    if (sum%3==0) cout<<0;
    else if (sum%3==1) {
        if (c1>0) cout<<1;
        else if (c2>1) cout<<2;
        else cout<<cnt-c0;
    } else {
        if (c2>0) cout<<1;
        else if (c1>1) cout<<2;
        else cout<<cnt-c0;
    }
}
