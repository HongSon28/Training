class Solution {
public:
    int m,n;
    int res=0;
    bool vis[21][21];
    vector<vector<int>>a;
    bool check(int i,int j) {
        if (i>=0&&j>=0&&i<m&&j<n&&!vis[i][j]&&a[i][j]!=-1) return true;
        return false;
    }
    void dfs(int i,int j) {
        vis[i][j]=true;
        if (a[i][j]==2) {
            int cnt=0;
            for (int i=0;i<m;i++)
                for (int j=0;j<n;j++)
                    if (vis[i][j]||a[i][j]==-1)
                        cnt++;
            if (cnt==m*n) res++;
        }
        if (check(i+1,j)) dfs(i+1,j);
        if (check(i,j+1)) dfs(i,j+1);
        if (check(i,j-1)) dfs(i,j-1);
        if (check(i-1,j)) dfs(i-1,j);
        vis[i][j]=false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        a=grid;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                vis[i][j]=false;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]==1) {
                    dfs(i,j);
                }
            }
        }
        return res;
    }
};
