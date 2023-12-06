#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int maxleft[n];
    int maxright[n];
    maxleft[0]=a[0];
    maxright[n-1]=a[n-1];
    for (int i=1;i<n;i++) {
        if (a[i]>maxleft[i-1]) {
            maxleft[i]=a[i];
        } else {
            maxleft[i]=maxleft[i-1];
        }
    }
    for (int i=n-2;i>=0;i--) {
        if (a[i]>maxright[i+1]) {
            maxright[i]=a[i];
        } else {
            maxright[i]=maxright[i+1];
        }
    }
    int res=0;
    for (int j=1;j<n-1;j++) {
        int i=maxleft[j-1];
        int k=maxright[j+1];
        res=max(res,2*i-3*a[j]+5*k);
    }
    cout<<res;
}
