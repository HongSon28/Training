#include<bits/stdc++.h>
using namespace std;
int expo(int a) {
    int tong=1;
    for (int i=a;i>=2;i--) {
        tong=tong*i;
    }
    return tong;
}
int main() {
    int t;
    cin>>t;
    int a[t];
    for (int i=0;i<t;i++) {
        int n,k;
        cin>>n>>k;
        if(n%expo(k)==0)
            a[i]=1;
    }
    for (int i=0;i<t;i++) {
        if (a[i]==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
