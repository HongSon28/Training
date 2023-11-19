#include<bits/stdc++.h>
using namespace std;
int a,b;
int mx,cnt,x;
int calc(int k) {
    int res=0;
    for (int i=1;i*i<=k;i++) {
        if (k%i==0) {
            int j=k/i;
            if (i==j) res++;
            else res+=2;
        }
    }
    return res;
}
int main() {
    freopen("UOCSO.INP","r",stdin);
    freopen("UOCSO.OUT","w",stdout);
    cin>>a>>b;
    for (int i=a;i<=b;i++) {
        int temp=calc(i);
        if (temp>mx) {
            mx=temp;
            x=i;
            cnt=1;
        } else if (temp==mx) cnt++;
    }
    cout<<x<<' '<<mx<<' '<<cnt;
}
