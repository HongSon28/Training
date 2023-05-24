#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]<0) a[i]=abs(a[i]);
        else a[i]=k-a[i];
    }
    cout<<*max_element(a,a+n);
    return 0;
}
