#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[21];
void check() {
    int cnt=0;
    for (int i=1;i<=n;i++) {
        if (a[i]==1) cnt++;
        else cnt--;
        if (cnt<0) return;
    }
    if (cnt!=0) return;
    k++;
    for (int i=1;i<=n;i++) {
        if (a[i]==1) cout<<'(';
        else cout<<')';
    }
    cout<<endl;
}
void rec(int x,int cnt) {
    a[x]=1;
    if (x==n) check();
    else rec(x+1,1);
    a[x]=2;
    if (x==n) check();
    else rec(x+1,cnt-1);
}
int main() {
    cin>>n;
    rec(1,0);
    cout<<k;
}
