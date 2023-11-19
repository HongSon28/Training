#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n+1];
    int res=0;
    bool t1=false,t2=false,t3=false;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        res+=a[i];
    }
    for (int i=1;i<n;i++) {
        if (a[i]+a[i+1]==2) t1=true;
        else if (a[i]+a[i+1]==0) t2=true;
        else t3=true;
    }
    if (t3==true) res+=4;
    else if (t1==true&&t2==false) res-=4;
    cout<<res;
}
