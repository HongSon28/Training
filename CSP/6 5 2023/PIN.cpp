#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,res;
int x1[N+5];
int x2[N+5];
int y11[N+5];
int y2[N+5];
bool check(int i,int j) {
    int x1a=x1[i],x1b=x1[j],x2a=x2[i],x2b=x2[j],y1a=y11[i],y1b=y11[j],y2a=y2[i],y2b=y2[j];
    if (((x1a>x1b&&x1a<x2b)||(x2a>x1b&&x2a<x2b)||(x1b>x1a&&x1b<x2a)||(x2b>x1a&&x2b<x2a)||(x1a==x1b&&x2a==x2b))&&((y1a>y1b&&y1a<y2b)||(y2a>y1b&&y2a<y2b)||(y1b>y1a&&y1b<y2a)||(y2b>y1a&&y2b<y2a)||(y1a==y1b||y2a==y2b))) return true;
    return false;
}
int main() {
    freopen("PIN.INP","r",stdin);
    freopen("PIN.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x1[i]>>y11[i]>>x2[i]>>y2[i];
    for (int i=1;i<n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (check(i,j)) {
                //cout<<i<<' '<<j<<endl;
                res++;
            }
        }
    }
    cout<<res;
}
