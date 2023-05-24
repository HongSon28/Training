#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;

long long n, k, p, tongmau=0;
long long a[MN];
void ReadData() {
	cin >> n >> k >> p;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		tongmau += a[i];
	}
}

void Solve() {
	long long t = k/n, r = k%n;
	long long tong = 0;
	tong += tongmau*t;
	for(int i = p-1; i < n; i++) {
		tong += a[i];
	}
	r -= (n-p+1);
	cout<<tong<<' '<<r<<endl;
	for(int i = 0; i<r; i++) {
		tong += a[i];
	}
	cout << tong;

}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    ReadData();
    Solve();
    return 0;
}
