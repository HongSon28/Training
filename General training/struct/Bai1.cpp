#include<bits/stdc++.h>
using namespace std;
double x,y,r;
struct toado {
    double x,y;
};
bool check(int x1, int y1) {
    if ((x1-x)*(x1-x)+(y1-y)*(y1-y)<=r*r)
        return true;
    return false;
}
int main() {
    cin>>x>>y>>r;
    int n;
    cin>>n;
    toado a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i].x>>a[i].y;
    }
    vector <int> kq;
    int dem=0;
    for (int i=0;i<n;i++) {
        if (check(a[i].x,a[i].y)==true) {
            dem++;
            kq.push_back(i+1);
        }
    }
    cout<<dem<<endl;
    for (int i=0;i<dem;i++) {
        cout<<kq[i]<<" ";
    }
}
