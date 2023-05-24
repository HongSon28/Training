#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[3],x,y;
    cin>>a[0]>>a[1]>>a[2]>>x>>y;
    sort(a,a+3);
    if (x>y)
        swap(x,y);
    if (a[0]<x&&a[1]<y)
        cout<<"CO";
    else
        cout<<"KHONG";
}
