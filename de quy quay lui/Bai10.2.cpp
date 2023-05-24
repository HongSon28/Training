#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[16];
float ans=0;
float kq;
float res=INT_MAX;
char c[4]={'+','-','*','/'};
void dequy(int k) {
    for (int i=0;i<4;i++) {
        if (c[i]=='+') {
            ans+=a[k];
        } else if (c[i]=='-') {
            ans-=a[k];
        } else if (c[i]=='*') {
            ans*=a[k];
        } else {
            ans/=a[k];
        }
        if (k==n) {
            if (m-ans<res&&m-ans>=0) {
                res=m-ans;
                kq=ans;
            }
        } else {
            dequy(k+1);
        }
        if (c[i]=='+') {
            ans-=a[k];
        } else if (c[i]=='-') {
            ans+=a[k];
        } else if (c[i]=='*') {
            ans/=a[k];
        } else {
            ans*=a[k];
        }
    }
}
int main() {
    cin>>m>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    ans=a[1];
    dequy(2);
    cout.precision(3);
    cout<<fixed<<kq;
}

