#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,greater<int>());
    int d[n];
    d[0]=0;
    for (int i=1;i<n;i++) {
        int temp=a[i]+i+1;
        d[i]=max(d[i-1],temp);
    }
    int res=1;
    for (int i=1;i<n;i++) {
        if (a[i]+n>=d[i-1]) res++;
    }
    cout<<res;
}
