#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
bool di[N+5];
int mx=0;
int resl,resr;
int main() {
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=2;i<=n;i++) {
        if (a[i]%a[i-1]==0||a[i-1]%a[i]==0) di[i]=true;
        //cout<<di[i]<<' ';
    }
    int i=1,l=1;
    int left=1,right=1;
    while (i<=n) {
        if (l>mx) {
            mx=l;
            resl=left,resr=right;
        }
        if (di[i]==true) {
            l++;
            right++;
        } else {
            l=1;
            left=right=i;
        }
        //cout<<i<<' '<<l<<' '<<left<<' '<<right<<endl;
        if (l>mx) {
            mx=l;
            resl=left,resr=right;
        }
        i++;
    }
    cout<<resl<<' '<<resr;
}
