#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,k,u,v,l,r;
int a[N+5];
int b[N+5];
int cycle=0;
bool check() {
    for (int i=1;i<=n;i++) {
        if (b[i]!=i) return false;
    }
    return true;
}
void findcycle() {
    int i=u,j=v;
    while (i<j) {
        swap(b[i],b[j]);
        i++;
        j--;
    }
    i=l,j=r;
    while (i<j) {
        swap(b[i],b[j]);
        i++;
        j--;
    }
    cycle++;
    while (!check()) {
        int i=u,j=v;
        while (i<j) {
            swap(b[i],b[j]);
            i++;
            j--;
        }
        i=l,j=r;
        while (i<j) {
            swap(b[i],b[j]);
            i++;
            j--;
        }
        cycle++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        a[i]=i;
        b[i]=i;
    }
    cin>>u>>v>>l>>r;
    findcycle();
    k%=cycle;
    while (k--) {
        int i=u,j=v;
        while (i<j) {
            swap(a[i],a[j]);
            i++;
            j--;
        }
        i=l,j=r;
        while (i<j) {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<'\n';
}
