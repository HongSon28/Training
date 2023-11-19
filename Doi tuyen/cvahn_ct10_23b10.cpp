#include<bits/stdc++.h>
using namespace std;
const int N=500;
struct point{
    double x,y;
} a[N+5];

int n;
double mx=1e18,res1,res2;
double area;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    a[n+1]=a[1];
    for (int i=1;i<=n;i++) area+=(a[i].x-a[i+1].x)*(a[i].y+a[i+1].y)/2;
    area=abs(area);
    cout<<area<<endl;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<i;j++) {
            if (j+1==i||(i==1&&j==n)||(i==n&&j==1)) continue;
            double temp=0;
            for (int k=j;k<i;k++) temp+=abs(a[k].x-a[k+1].x)*(a[k].y+a[k+1].y)/2;
            temp+=(a[i].x-a[j].x)*(a[i].x+a[j].x)/2;
            temp=abs(temp);
            double temp2=area-temp;
            if (mx>abs(temp-temp2)) {
                mx=abs(temp-temp2);
                res1=j;
                res2=i;
            }
            cout<<j<<' '<<i<<' '<<temp<<' '<<temp2<<endl;
        }
    }
    cout<<res1<<' '<<res2;
}
