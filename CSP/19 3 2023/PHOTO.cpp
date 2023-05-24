#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[5][N+1],b[N+1];
bool comp(int x, int y) {
    int cnt=0;
    for (int i=0;i<5;i++) {
        if (a[i][x]<a[i][y]) cnt++;
    }
    if (cnt>=3) return true;
    return false;
}
int main() {
    freopen("PHOTO.INP","r",stdin);
    freopen("PHOTO.OUT","w",stdout);
    cin>>n;
    for (int q=0;q<5;q++) {
        for (int j=0;j<n;j++) {
            int temp;
            cin>>temp;
            a[q][temp]=j;
        }
    }
    for (int i=0;i<n;i++) {
        b[i]=i+1;
    }
    sort(b,b+n,comp);
    for (int i=0;i<n;i++) cout<<b[i]<<' ';
}
