#include<bits/stdc++.h>
using namespace std;
int n, m;
long long res;
priority_queue<long long>q;
int main() {
    freopen("LINEUP.INP","r",stdin);
    freopen("LINEUP.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        long long temp;
        cin>>temp;
        q.push(temp);
    }
    while (m--) {
        long long temp=q.top();
        q.pop();
        res+=temp;
        temp--;
        q.push(temp);
    }
    cout<<res;
}
