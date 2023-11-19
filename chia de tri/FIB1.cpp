#include<bits/stdc++.h>
using namespace std;
long long len[71];
int t,n,k;
char rec(long long c,long long pos) {
    if (c==0) return 'a';
    if (c==1) return 'b';
    if (pos>len[c-2]) return rec(c-1,pos-len[c-2]);
    else return rec(c-2,pos);
}
int main() {
    freopen("FIB1.INP","r",stdin);
    freopen("FIB1.OUT","w",stdout);
    len[0]=1,len[1]=1;
    for (int i=2;i<=70;i++) len[i]=len[i-1]+len[i-2];
    cin>>t;
    while (t--) {
        cin>>n>>k;
        cout<<rec(n,k)<<endl;
    }
}
