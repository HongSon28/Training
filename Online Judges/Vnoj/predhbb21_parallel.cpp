#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[13];
    while (cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]>>a[10]>>a[11]>>a[12]) {
        if (a[1]==0) break;
        sort(a+1,a+13);
        if (a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[5]==a[6]&&a[6]==a[7]&&a[7]==a[8]&&a[9]==a[10]&&a[10]==a[11]&&a[11]==a[12]) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
