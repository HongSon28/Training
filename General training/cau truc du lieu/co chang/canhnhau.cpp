#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n+1);
    for (int i=0;i<m;i++) {
        int p,q;
        cin>>p>>q;
        if (p!=q) {
            v[p].push_back(q);
            v[q].push_back(p);
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<' ';
        cout<<'0'<<endl;
    }
}
