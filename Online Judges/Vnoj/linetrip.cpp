#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort (a,a+n);
    int demduong=0;
    int demam=0;
    for (int i=0;i<n;i++) {
        if (a[i]>0)
            demduong+=1;
        if (a[i]<0)
            demam+=1;
    }
    if (demam==0) {
        cout<<a[n-1]*2;
    } else if (demduong==0) {
        cout<<abs(a[0])*2;
    } else {
        cout<<(abs(a[0])+a[n-1])*2;
    }
}
