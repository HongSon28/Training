#include<bits/stdc++.h>
using namespace std;
long long a,b,k;
long long cnt(long long x) {
    long long ans=0;
    while (x!=0) {
        x/=10;
        ans++;
    }
    return ans;
}
long long power(long long x,long long y) {
    long long ans=1;
    for (int i=1;i<=y;i++) ans*=x;
    return ans;
}
int main() {
    freopen("SODACBIET.INP","r",stdin);
    freopen("SODACBIET.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a>>b>>k;
    if (k==10) {
        cout<<0;
        return 0;
    }
    for (int i=0;i<=18;i++) {
        long long t1=a*power(10,i+1)+b;
        //cout<<t1<<endl;
        if (t1%(k-10)!=0) continue;
        long long t2=t1/(k-10);
        if (cnt(t2)==i) {
            cout<<t2;
            return 0;
        }
    }
}
