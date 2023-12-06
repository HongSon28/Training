#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100];
void out(){
    for (int i=1;i<=n;i++) cout<<a[i];
    cout<<endl;
}
void rec(int m) {
    for (int i=0;i<k;i++) {
        a[m]=i;
        if (m==n) out();
        else rec(m+1);
    }
}
int main() {
    cin>>n>>k;
    rec(1);
}

