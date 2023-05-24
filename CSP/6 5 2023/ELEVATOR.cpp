#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int sum;
int res=1;
int a[N+5];
bool c[N+5];
int main() {
    freopen("ELEVATOR.INP","r",stdin);
    freopen("ELEVATOR.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        if (sum+a[i]>m) {
            res++;
            sum=a[i];
        } else sum+=a[i];
    }
    cout<<res;
}
