#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int BLOCK_SIZE=320;
int n,m;
int cnt[N/BLOCK_SIZE+5][N+5];
int a[N+5];
int query (int l,int r,int k) {
    int blockL=(l+BLOCK_SIZE-1)/BLOCK_SIZE;
    int blockR=r/BLOCK_SIZE;
    if (blockL>=blockR) return count(a+l,a+r+1,k);
    int sum=0;
    for (int i=blockL;i<blockR;i++) sum+=cnt[i][k];
    for (int i=l,lim=blockL*BLOCK_SIZE;i<lim;i++) if (a[i]==k) sum++;
    for (int i=blockR*BLOCK_SIZE;i<=r;i++) if (a[i]==k) sum++;
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]>N) continue;
        cnt[i/BLOCK_SIZE][a[i]]++;
    }
    while (m--) {
        int l,r;
        cin>>l>>r;
        int t=r-l+1,res=0;
        for (int i=1;i<=t;i++) {
            if (i>N) break;
            int temp=query(l,r,i);
            if (temp==i) res++;
            t-=temp;
        }
        cout<<res<<'\n';
    }
}
