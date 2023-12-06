#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int gt=1, d=0,i,b=n-1;
    int a[n][n];
    while (gt<=n*n) {
        for (i=d;i<=b;i++) {
            a[d][i]=gt;
            gt++;
        }
        for (i=d+1;i<=b;i++) {
            a[i][b]=gt;
            gt++;
        }
        for (i=b-1;i>=d;i--) {
            a[b][i]=gt;
            gt++;
        }
        for (i=b-1;i>d;i--) {
            a[i][d]=gt;
            gt++;
        }
        d++;
        b--;
    }
    for (i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
