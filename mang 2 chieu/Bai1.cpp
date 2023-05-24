#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int tonga=0;
    int tongb=0;
    int tongc=0;
    int tongd=0;
    int tonge=0;
    int tongf=0;
    cin>>n;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        tonga+=a[i][i];
    }
    for (int j=n-1;j>=0;j--) {
        tongb+=a[n-1-j][j];
    }
    for (int i=0;i<n-1;i++) {
        tongc+=a[i][i+1];
    }
    for (int i=1;i<n;i++) {
        tongc+=a[i][i-1];
    }
    for (int i=0;i<n-1;i++) {
        tongd+=a[i][n-2-i];
    }
    for (int i=1;i<n;i++) {
        tongd+=a[i][n-i];
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            tonge+=a[i][j];
        }
    }
    for (int i=1;i<n;i++) {
        for (int j=n-i;j<n;j++) {
            tongf+=a[i][j];
        }
    }
    cout<<tonga<<endl;
    cout<<tongb<<endl;
    cout<<tongc<<endl;
    cout<<tongd<<endl;
    cout<<tonge<<endl;
    cout<<tongf;
}
