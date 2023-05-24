#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[25];
bool used[25];
void out() {
    for (int i=1;i<=k;i++) cout<<a[i]<<' ';
    cout<<endl;
}
void rec(int m,int mn) {
    for (int i=mn+1;i<=n;i++) {
        if (used[i]==false) {
            a[m]=i;
            used[i]=true;
            if (m==k) out();
            else rec(m+1,i);
            used[i]=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("SUBSETS.INP","r",stdin);
    //freopen("SUBSETS.OUT","w",stdout);
    cin>>n>>k;
    rec(1,0);
}

