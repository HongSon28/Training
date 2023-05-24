#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int mx=0;
    for (int i=0;i<n-1;i++) {
        int tong=0;
        for (int j=i;j<n;j++) {
            tong+=a[j];
            if (tong==0)
                mx=max(j-i+1,mx);
        }
    }
    if (mx==0)
        cout<<"NO SOLUTION";
    else
        cout<<mx;
}
