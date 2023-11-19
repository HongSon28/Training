// Solution: Boris Mihov

#include <algorithm>
#include <iostream>
#include <cassert>
#include <numeric>
#include <vector>

typedef long long llong;
const int MAXN = 2000 + 10;
const llong INF = 2e9 + 10;

int l[MAXN], n;
int inputC[MAXN];
int c[MAXN][MAXN];
llong dpPlus[MAXN][MAXN];
llong dpMinus[MAXN][MAXN];
bool blPlus[MAXN][MAXN];
bool blMinus[MAXN][MAXN];
std::vector <int> g[MAXN];

llong plus(int node, int incoming);
llong minus(int node, int wanted);

void dfs(int node, int p)
{
    for (int &i : g[node])
    {
        if (i == p)
        {
            std::swap(i, g[node].back());
            g[node].pop_back();
            break;
        }
    }

    for (const int &i : g[node])
    {
        dfs(i, node);
    }
}

llong plus(int node, int incoming)
{
    if (incoming >= n+1) return 0;
    if (g[node].empty())
    {
        assert(incoming >= 1);
        return 0;
    }

    if (blPlus[node][incoming]) return dpPlus[node][incoming];
    blPlus[node][incoming] = true;
    dpPlus[node][incoming] = minus(node, 0);

    llong lsum = 0;
    for (const int &i : g[node])
    {
        if (incoming == 1) lsum += minus(i, 0);
        else lsum += plus(i, incoming - 1);
    }

    dpPlus[node][incoming] = std::min(dpPlus[node][incoming], std::min(lsum, INF));
    return dpPlus[node][incoming];
}

llong minus(int node, int wanted)
{
    //std::cout<<"get "<<node<<' '<<wanted<<'\n';
    if (wanted >= n+1) return INF;
    if (g[node].empty())
    {
        if (l[node] >= wanted + 1) return c[node][wanted + 1];
        return INF;
    }

    if (blMinus[node][wanted]) return dpMinus[node][wanted];
    blMinus[node][wanted] = true;
    dpMinus[node][wanted] = minus(node, wanted + 1);

    llong sum = 0;
    for (const int &i : g[node])
    {
        if (wanted >= 1) sum += plus(i, wanted);
        else sum += minus(i, 0);
    }

    if (wanted + 1 <= l[node])
    {
        dpMinus[node][wanted] = std::min(dpMinus[node][wanted], sum + c[node][wanted + 1]);
    }

    for (const int &i : g[node])
    {
        llong curr = sum + minus(i, wanted + 1);
        if (wanted == 0) curr -= minus(i, 0);
        else curr -= plus(i, wanted);

        if (curr < dpMinus[node][wanted])
        {
            dpMinus[node][wanted] = curr;
        }
    }

    return dpMinus[node][wanted];
}

void solve()
{
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = n + 1 ; j >= l[i] + 1 ; --j) c[i][j] = INF;
        for (int j = l[i] ; j >= 1 ; --j)
        {
            c[i][j] = std::min(c[i][j + 1], inputC[j]);
        }
    }

    dfs(1, 0);
    llong res = minus(1, 0);
    if (res >= INF) std::cout << -1 << '\n';
    else std::cout << res << '\n';
}

void read()
{
    std::cin >> n;
    for (int i = 1 ; i <= n ; ++i) std::cin >> inputC[i];
    for (int i = 1 ; i <= n ; ++i) std::cin >> l[i];
    for (int i = 2 ; i <= n ; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

}

void fastIO()
{
    std::ios_base :: sync_with_stdio(0);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
}

int main()
{
    freopen("garden.33.in","r",stdin);
    fastIO();
    read();
    solve();

    return 0;
}
