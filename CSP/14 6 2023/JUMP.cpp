#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int a[N+5];
int main() {
    freopen("JUMP.INP","r",stdin);
    freopen("JUMP.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    while (m--) {
        int type,x,y,cnt=0;
        cin>>type;
        if (type==1) {
            cin>>x>>y;
            a[x]=y;
        }
        else {
            cin>>x;
            while (x<=n) {
                cnt++;
                x+=a[x];
            }
            cout<<cnt<<endl;
        }
    }
}
