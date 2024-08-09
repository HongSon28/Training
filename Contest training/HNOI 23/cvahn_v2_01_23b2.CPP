#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,ii,jj,j;
double x[N+5],y[N+5];
double res=0;
double calc(int i,int j,int k) {
    double a=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    double b=sqrt((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]));
    double c=sqrt((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]));
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main() {
    freopen("QUADIL.INP","r",stdin);
    freopen("QUADIL.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (int i=1;i<=n-3;i++) {
        ii=i+1,j=i+2,jj=i+3;
        while (j<=n-1) {
            while (ii<j) {
                if (calc(i,ii+1,j)>calc(i,ii,j)&&ii+1<j) ii++;
                else break;
            }
            while (jj<=n) {
                if (calc(i,j,jj+1)>calc(i,j,jj)&&jj+1<=n) jj++;
                else break;
            }
            res=max(res,calc(i,ii,j)+calc(i,j,jj));
            j++;
            if (jj<=j) jj=j+1;
        }
    }
    cout<<fixed<<setprecision(1)<<res;
}
