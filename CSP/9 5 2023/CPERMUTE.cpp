#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
bool sd[21]={};
int a[21];
bool check() {
    for (int i=1;i<=n;i++)
        if (a[i]==i) return false;
    return true;
}
void rec(int k) {
    for (int i=1;i<=n;i++) {
        if (sd[i]==false) {
            a[k]=i;
            sd[i]=true;
            if (k==n) {
                if (check()==true) cnt++;
            } else {
                rec(k+1);
            }
            sd[i]=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("CPERMUTE.INP","r",stdin);
    freopen("CPERMUTE.OUT","w",stdout);
    cin>>n;
    rec(1);
    cout<<cnt;
}
