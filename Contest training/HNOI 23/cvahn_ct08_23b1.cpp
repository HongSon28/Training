#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
double t[N+5];
int n,d,res;
int main() {
    freopen("DUAROBOT.INP","r",stdin);
    freopen("DUAROBOT.OUT","w",stdout);
    cin>>n>>d;
    for (int i=1;i<=n;i++) {
        double temp;
        cin>>temp;
        t[i]=(double)d/temp+i;
    }
    for (int i=1;i<=n;i++) {
        for (int j=i-1;j>=1;j--) {
            if (t[i]<t[j]) res++;
        }
    }
    cout<<res;
}
