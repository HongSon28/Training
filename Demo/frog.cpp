#include<bits/stdc++.h>
using namespace std;
bool comp(int a, int b) {
    return a>b;
}
int main() {
    int m,n,k;
    cin>>m>>n>>k;
    int a[m][n];
    int sl[100000]={};
    int dem=0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
            if (sl[a[i][j]]==0)
                dem++;
            sl[a[i][j]]++;
        }
    }
    sort(sl,sl+n*m+1,comp);
    int tong=0;
    for (int i=0;i<k;i++) {
        tong+=sl[i];
    }
    cout<<tong;
}
