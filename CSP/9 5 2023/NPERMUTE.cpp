#include<bits/stdc++.h>
using namespace std;
int n;
bool sd[21]={};
int a[21];
void out() {
    for (int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void rec(int k) {
    for (int i=1;i<=n;i++) {
        if (sd[i]==false) {
            a[k]=i;
            sd[i]=true;
            if (k==n) {
                out();
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
    //freopen("NPERMUTE.INP","r",stdin);
    //freopen("NPERMUTE.OUT","w",stdout);
    cin>>n;
    rec(1);
}


