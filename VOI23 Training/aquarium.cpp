#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int m,h;
int y[N+5];
int n,k;
double a[N+5],b[N+5],c[N+5],d[N+5],e[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>h;
    for (int i=0;i<=m;i++) cin>>y[i];
    for (int i=1;i<=m;i++) {
        int X=y[i-1],Y=y[i];
        if (X>Y) swap(X,Y);
        e[Y]++;
        if (X==Y) continue;
        double A=1/(double)(Y-X)/2;
        //cout<<i<<' '<<A<<' '<<X<<' '<<Y<<' '<<-2*A*X<<' '<<A*X*X<<endl;
        a[X]+=A;
        a[Y]-=A;
        b[X]+=-2*A*X;
        b[Y]-=-2*A*X;
        c[X]+=A*X*X;
        c[Y]-=A*X*X;
        d[Y]+=A*Y*Y-2*A*X*Y+A*X*X;
    }
    //cout<<endl;
    for (int i=1;i<=h;i++) {
        a[i]+=a[i-1];
        b[i]+=b[i-1];
        c[i]+=c[i-1];
        d[i]+=d[i-1];
        e[i]+=e[i-1];
        //cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<' '<<d[i]<<' '<<e[i]<<endl;
    }
    for (int i=1;i<=h;i++) e[i]+=e[i-1];
    cin>>n;
    while (n--) {
        cin>>k;
        cout.precision(4);
        cout<<fixed<<a[k-1]*k*k+b[k-1]*k+c[k-1]+d[k-1]+e[k-1]<<'\n';
    }
}
