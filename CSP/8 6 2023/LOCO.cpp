#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
struct mat{
    int x,y;
    ll a[5][5];
};
mat operator * (mat a, mat b) {
    mat c;
    c.x=a.x,c.y=b.y;
    for (int i=1;i<=c.x;i++)
        for (int j=1;j<=c.y;j++)
            c.a[i][j]=0;
    for (int i=1;i<=a.x;i++) {
        for (int j=1;j<=b.y;j++) {
            for (int k=1;k<=a.y;k++) {
                c.a[i][j]+=a.a[i][k]*b.a[k][j]%m;
                c.a[i][j]%=m;
            }
        }
    }
    return c;
}
mat power (mat a, ll x) {
    if (x==1) return a;
    mat temp=power(a, x/2);
    if (x%2==0) return temp*temp;
    else return temp*temp*a;
}
mat a,x;
int main() {
    freopen("LOCO.INP","r",stdin);
    freopen("LOCO.OUT","w",stdout);
    cin>>n>>m;
    if (n==1) {
        cout<<1;
        return 0;
    }
    if (n==2) {
        cout<<2;
        return 0;
    }
    a.x=a.y=3;
    a.a[1][1]=a.a[1][2]=a.a[1][3]=a.a[2][1]=a.a[3][2]=1;
    a.a[2][2]=a.a[2][3]=a.a[3][1]=a.a[3][3]=0;
    x.x=3;
    x.y=1;
    x.a[1][1]=2;
    x.a[2][1]=x.a[3][1]=1;
    cout<<(power(a,n-2)*x).a[1][1];
}
