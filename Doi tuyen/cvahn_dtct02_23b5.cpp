#include<bits/stdc++.h>
using namespace std;
const int N=23;
int n;
int a[N+5];
int used[N+5];
double res=-1e9;
void check() {
    int sum=0;
    for (int i=1;i<=n;i++){
        if (used[i]) sum+=a[i];
    }
    //cout<<sum<<' '<<sin(sum)<<endl;
    res=max(res,sin(sum));
}
void rec(int k) {
    for (int i=0;i<=1;i++) {
        used[k]=i;
        if (k==n) check();
        else rec(k+1);
    }
}
int main() {
    freopen("SINMAX.INP","r",stdin);
    freopen("SINMAX.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    rec(1);
    cout.precision(7);
    cout<<fixed<<res;
}
