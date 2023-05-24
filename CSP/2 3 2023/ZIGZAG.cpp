#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll nxM = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x, y, z;
    cin >> n >> x >> y >> z;
    if (x % 2 == 0) {
        cout << n*x - y + 1 << '\n';
    }
    else {
        cout << n*x - (n - y) << '\n';
    }
    if (z % n == 0) {
        int a = z/n;
        if (a % 2 == 0) {
            cout << a << " " << 1;
        }
        else {
            cout << a << " " << n;
        }
    }
    else {
        int a = z/n + 1;
        if (a % 2 == 0) {
            cout << a << " " << n*a - z + 1;
        }
        else {
            cout << a << " " << z - n*a + n;
        }
    }
}
