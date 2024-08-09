#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    int tich=1;
    int dem=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=n-1;i>=1;i-=2) {
        if (a[i]==a[i-1]) {
            tich*=a[i];
            dem+=1;
        }
        if (dem==2)
            break;
    }
    if (dem<2)
        cout<<"0";
    else
        cout<<tich;
}
