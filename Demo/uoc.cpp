#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxN = 1e5+1;
long long n, k, a[maxN], b, wood[maxN];

long long BS(long long v)
{
	int l = 1, h = n, mid;
	while (l <= h)
	{
		mid = (l + h)/2;
		if (wood[mid] < v) h = mid - 1; else l = mid + 1;
	}
	return h;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("saw.inp","r",stdin);
	//freopen("saw.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
        cin >> a[i];
	sort (a + 1, a + n + 1);
	wood[n] = 0;
	for (int i = n-1; i >= 0; --i) wood[i] = wood[i+1] + a[i+1];
	for (int i = n-1; i >= 0; --i) wood[i] -= a[i] * (n-i);
	//for (int i=1;i<=n;i++) cout<<wood[i]<<endl;
	for (int i = 1; i <= k; ++i)
    {
        cin >> b;
        long long j = BS(b);
        long long so = ceil (((double)b - wood [j+1]) / (n - j));
        cout<<j<<' '<<so<<endl;
        cout << a[j+1] - so << ' ';
    }
}
