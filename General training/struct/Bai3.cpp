#include<bits/stdc++.h>
using namespace std;
struct dt {
    double x,y,r;
};
int main() {
    int n;
    cin>>n;
    dt a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i].x>>a[i].y>>a[i].r;
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            double d=sqrt(pow(a[i].x-a[j].x,2)+pow(a[i].y-a[j].y,2));
            if (a[i].r+a[j].r>d&&abs(a[i].r-a[j].r)<d) {
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            double d=sqrt(pow(a[i].x-a[j].x,2)+pow(a[i].y-a[j].y,2));
            if (d<=abs(a[i].r-a[j].r)) {
                if (a[i].r>a[j].r) {
                    cout<<i+1<<" "<<j+1<<endl;
                } else {
                    cout<<j+1<<" "<<i+1<<endl;
                }
            }
        }
    }
}
