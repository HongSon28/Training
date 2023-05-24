#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    string kq[q];
    sort(a,a+n);
    for (int i=0;i<q;i++) {
        int x;
        cin>>x;
        if (x<a[0]||x>a[n-1])
            kq[i]="No";
        else
            kq[i]="Yes";
    }
    for (int i=0;i<q;i++)
        cout<<kq[i]<<endl;
}
