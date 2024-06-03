#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int b[65];
int main() {
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i = 0; i <= 20; i++) // chạy từ 0 -> 20 không sao cả
    for (int u = 0; u < n; u++)
        if ((a[u] & (1 << i)) > 0) b[i]++;
    int s = 0;
    for (int i = 0; i <= 20; i++) {
        cout<<b[i]<<' ';
        if (b[i] % 2 == 0)
            s += 0;
        else
            s += (1 << i);
    }
    cout<<s;
}
