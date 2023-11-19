#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int c[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        c[a[i]]++;
    }
    cout<<*max_element(c+1,c+1+n);
}
