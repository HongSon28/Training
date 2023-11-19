#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull power[100];
int cnt;
void bits(ull n, int k) {
    //cout<<k<<endl;
    if (k>=0){
        if (n<power[k])
            bits(n,k-1);
        else {
            bits(n%power[k],k-1);
            cnt++;
        }
    }
}
int main() {
    //freopen("BDIGIT.INP","r",stdin);
    //freopen("BDIGIT.OUT","w",stdout);
    power[0]=1;
    for (int i=1;i<=63;i++) power[i]=power[i-1]*2;
    int t;
    cin>>t;
    while (t--) {
        ull n;
        cnt=0;
        cin>>n;
        bits(n,63);
        if (cnt%2==0) cout<<0<<endl;
        else cout<<1<<endl;
    }
}
