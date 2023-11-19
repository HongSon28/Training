#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
double a[N+5],b[N+5];
double res;
double x,y;
int cnt;
int main() {
    freopen("SUREBET.INP","r",stdin);
    freopen("SUREBET.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    sort(a+1,a+1+n,greater<double>());
    sort(b+1,b+1+n,greater<double>());
    int i=1,j=1;
    x=a[1],y=b[1];
    cnt=2;
    while (i<=n&&j<=n) {
        res=max(res,min(x,y)-cnt);
        if (x<y) {
            i++;
            cnt++;
            x+=a[i];
        } else {
            j++;
            cnt++;
            y+=b[j];
        }
    }
    cout.precision(4);
    cout<<fixed<<res;
}
