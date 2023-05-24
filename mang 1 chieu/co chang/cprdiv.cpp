#include<bits/stdc++.h>
using namespace std;
#define N 60000
int main() {
    int n,m;
    cin>>n>>m;
    int c1[N]={},c2[N]={},c3[N];
    for (int i=2;i<=n;i++) {
        int temp=i;
        for (int j=2;j*j<=i;j++) {
            while (temp%j==0) {
                temp/=j;
                c1[j]++;
            }
        }
        if (temp!=1) {
            c1[temp]++;
        }
    }
    for (int i=2;i<=m;i++) {
        int temp=i;
        for (int j=2;j<=sqrt(i);j++) {
            while (temp%j==0) {
                temp/=j;
                c2[j]++;
            }
        }
        if (temp!=1) {
            c2[temp]++;
        }
    }
    for (int i=2;i<=n-m;i++) {
        int temp=i;
        for (int j=2;j<=sqrt(i);j++) {
            while (temp%j==0) {
                temp/=j;
                c3[j]++;
            }
        }
        if (temp!=1) {
            c3[temp]++;
        }
    }
    int res=0;
    for (int i=2;i<=n;i++) {
        if (c1[i]-c2[i]-c3[i]>0)
            res++;
    }
    cout<<res;
}
