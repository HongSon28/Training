#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int cnt_components, time_dfs, number[maxn], low[maxn];
stack < int > vertex;
bool is_deleted[maxn];
vector < int > adj[maxn];

void dfs(int u) // Giải thuật Tarjan
{
    number[u] = ++time_dfs;
    low[u] = num[u];

    for (int v: adj[u])
    {		
        if (is_deleted[v]) // Đỉnh v đã xóa rồi thì bỏ qua.
            continue;
        if (!number[v]) // đỉnh v chưa được đánh số => chưa được thăm.
        {
            dfs(v); // Thăm v.
            low[u] = min(low[u], low[v]); // Cực tiểu hóa low[u].
        }
        else // Nếu v đã thăm.
        {
            low[u] = min(low[u], num[v]); // Cực tiểu hóa low[u] theo num[v].
        }
    }

    // Bắt đầu kiểm tra đỉnh u có phải chốt hay không.
    if (low[u] == num[u]) 
    {
        // In ra chỉ số của thành phần liên thông này.
        cout << "Strongly Connected Component " << ++cnt_components << ": ";
        
        // Liệt kê thành phần liên thông mạnh chốt là u.
        int v;
        do
        {
            v = vertex.top(); // Lấy các đỉnh từ trong stack ra.
            cout << v << ' ';
            vertex.pop();
            is_deleted[v] = 1;
        }
        while (v != u); // Nếu đã lấy ra chốt u thì kết thúc TPLTM chốt u.
        
        cout << endl;
    }
}

main()
{
    // Nhập dữ liệu đồ thị.
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    // Duyệt qua các đỉnh, nếu đỉnh nào chưa thăm thì bắt đầu dfs từ đỉnh đó.
    for (int u = 1; u <= N; ++u)
        if (!number[u])
            dfs(u);
}