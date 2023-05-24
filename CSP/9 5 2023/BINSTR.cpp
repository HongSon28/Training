#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
void out(){
    for (int i=1;i<=n;i++) cout<<a[i];
    cout<<'\n';
}
void rec(int k) {
    for (int i=0;i<=1;i++) {
        a[k]=i;
        if (k==n) out();
        else rec(k+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("BINSTR.INP","r",stdin);
    //freopen("BINSTR.OUT","w",stdout);
    cin>>n;
    rec(1);
}

