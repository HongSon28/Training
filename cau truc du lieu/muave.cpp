#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,k;
    cin>>n>>k>>m;
    int h[n+1],d[n+1];
    queue<int>q;
    for (int i=1;i<=n;i++) {
        cin>>h[i];
        q.push(i);
        d[i]=0;
    }
    for (int i=1;i<=m;i++) {
        int x=q.front();
        q.pop();
        d[x]++;
        if (h[x]>k)q.push(x);
        if (q.empty())break;
    }
    for (int i=1;i<=n;i++)cout<<d[i]<<' ';
}
