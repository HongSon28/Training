#include<bits/stdc++.h>
using namespace std;
struct td{
    double x,y;
};
int main() {
    int n,cnt=0;
    cin>>n;
    double res=0;
    td a[n];
    for (int i=0;i<n;i++) cin>>a[i].x>>a[i].y;
    for (int i=0;i<n-2;i++) {
        for (int j=i+1;j<n-1;j++) {
            double l1=pow((a[j].x-a[i].x),2)+pow((a[j].y-a[i].y),2);
            for (int k=j+1;k<n;k++) {
                double l2=pow((a[k].x-a[i].x),2)+pow((a[k].y-a[i].y),2);
                double l3=pow((a[k].x-a[j].x),2)+pow((a[k].y-a[j].y),2);
                if (l2+l3==l1) {
                    cnt++;
                    res=max(res,sqrt(l2)*sqrt(l3)/2);
                } else if (l1+l2==l3) {
                    cnt++;
                    res=max(res,sqrt(l2)*sqrt(l1)/2);
                } else if (l1+l3==l2) {
                    cnt++;
                    res=max(res,sqrt(l1)*sqrt(l3)/2);
                }
            }
        }
    }
    cout<<cnt<<endl;
    if (cnt>0) {
        cout.precision(3);
        cout<<fixed<<res;
    }
}
