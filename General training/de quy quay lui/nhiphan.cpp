#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
void out(){
    for (int i=1;i<=n;i++) cout<<a[i];
    cout<<endl;
}
void rec(int k) {
    for (int i=0;i<=1;i++) {
        a[k]=i;
        if (k==n) out();
        else rec(k+1);
    }
}
int main() {
    cin>>n;
    for (int i=0;i<=1;i++) {
        a[1]=i;
        rec(2);
    }
}
