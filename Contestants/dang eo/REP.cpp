#include<bits/stdc++.h>
using namespace std;
const int maxn = round(1e5) + 1;
struct X
{
    int a, b, c;

};
X s[maxn], z[maxn];
int n, nz = 0;
bool ss(X x, X y)
{
    if (x.b < y.b) return true;
    if (x.b == y.b && x.c < y.c) return true;
    else return false;
}
void Enter()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i].a >> s[i].b >> s[i].c;
    sort(s+1, s + n + 1, ss);
}
int bs(int x)
{
    int l, r, mid, i;
    if (x <= z[1].a || nz == 0) i = 0;
    else
    {
       if(z[nz].a < x) i = nz;
       else
       {
           l = 1; r = nz;
           while (l <= r)
           {
               mid = (l + r)/2;
               if(z[mid].a <= x) l = mid + 1;
               else r = mid - 1;
           }
           i = r;
       }
       int cnt = z[nz].c - z[i].c;
       if(i > 0 && z[i].b >= x)
        cnt += z[i].b - x + 1;
       return cnt;
    }
}
void Solve()
{
    int k = 0;
    for(int i = 1; i <= n; i++)
    {
        k = s[i].c - bs(s[i].a);
        if (k <= 0) continue;
        int j = nz;
        while (j > 0 && s[i].b - z[j].b - (z[nz].c - z[j].c) <= k) j--;

        z[j+1].b = s[i].b;
        z[j+1].a = s[i].b - k - (z[nz].c - z[j].c) + 1;
        z[j+1].c = z[j].c + z[j+1].b - z[j+1].a + 1;
        nz = j + 1;
    }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   freopen("REP.INP","r",stdin);
   freopen("REP.OUT","w",stdout);
    Enter();
    Solve();
    cout << z[nz].c;
}

