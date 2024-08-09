#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,l;
int c[N+5];
int res;
int main() {
    cin>>n>>l;
    for (int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+1+n,greater<int>());
    int h=n;
    while (h>0&&c[h]<h) h--;
    h++;
    while (h>0&&l>0) {
        c[h]++;
        h--;
        l--;
    }
    sort(c+1,c+1+n,greater<int>());
    h=n;
    while (h>0&&c[h]<h) h--;
    cout<<h;
}
