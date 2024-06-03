#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int>v;
    int n;
    cin>>n;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
            v.push_back(a[i][j]);
        }
    }
    sort(v.begin(),v.end());
    int gt=0;
    int d=0,i,b=n-1;
    cout<<n<<endl;
    while (gt<n*n) {
        for (i=d;i<=b;i++) {
            a[d][i]=v[gt];
            gt++;
        }
        for (i=d+1;i<=b;i++) {
            a[i][b]=v[gt];
            gt++;
        }
        for (i=b-1;i>=d;i--) {
            a[b][i]=v[gt];
            gt++;
        }
        for (i=b-1;i>d;i--) {
            a[i][d]=v[gt];
            gt++;
        }
        d++;
        b--;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}
