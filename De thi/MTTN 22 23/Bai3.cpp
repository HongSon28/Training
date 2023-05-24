#include<bits/stdc++.h>
using namespace std;
int main() {
    int res=INT_MIN;
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int s=0;s<n;s++) {
        for (int i=0;i<n;i++) {
            b[i]=a[(i+s)%n];//tao mang b
            cout<<b[i]<<' ';
        }
        cout<<endl;
    }

}
