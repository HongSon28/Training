#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, res = 0;
ll sum(ll x, ll y)
{
    ll len = (y - x + 1);
    return (x+y) * len / 2;
}
int main()
{
    freopen("DEMDOAN.INP","r",stdin); freopen("DEMDOAN.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(ll i = 1; sum(1,i) <= n; i++)
    {
        if( (2*n) % i == 0 && (i % 2) != ((2*n/i) % 2) )
        {
            res++;
            //cout << i << '\n';
        }
    }
    cout << res;
}
