#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int m,n,k;
string a,b;
bitset<N+5>eq[205];
void gauss() {
    vector<int>res;
    for(int i=1;i<=n+m;i++) {
       int pos=0;
       for(int j=1;j<=k;j++) {
           if(eq[i][j]) {
                pos=j;
                break;
            }
        }
        for(int j=1;j<=n+m;j++) {
            if((i!=j)&&(eq[j][pos])) eq[j]^=eq[i];
        }
    }
    for(int i=1;i<=n+m;i++) {
        int pos=0;
        for(int j=1;j<=k;j++) {
            if(eq[i][j])
            {
                pos=j;
                break;
            }
        }
        if(eq[i][k+1])
            if(pos!=0) res.push_back(pos);
            else {
                cout<<-1;
                return;
            }
    }
    if(res.empty())
    {
        cout<<-1;
        return;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<' ';
}
int main() {
    cin>>m>>n>>k;
    cin>>a>>b;
    a=' '+a,b=' '+b;
    for (int i=1;i<=m+n;i++) {
        if (a[i]!=b[i]) eq[i].set(k+1);
    }
    for (int i=1;i<=k;i++) {
        int x,y;
        cin>>x>>y;
        y+=m;
        eq[x].set(i);
        eq[y].set(i);
    }
    gauss();
}
