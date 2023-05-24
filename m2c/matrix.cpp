#include <bits/stdc++.h>
using namespace std;
long long a[501][501];
long long n,m;
long long tr[501];

int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    long long res = INT_MIN;
    for (int i = 1; i <= n; i++){
        memset(tr, 0, sizeof(tr));
        for (int u = i; u <= n; u++){
            long long sum = 0;
            long long best = INT_MIN;
            for (int j = 1; j <= m; j++){
                tr[j] += a[u][j];
                sum = max(tr[j], sum + tr[j]);
                best = max(best, sum);
            }
            res = max(best, res);
        }
    }
    cout << res;
}
