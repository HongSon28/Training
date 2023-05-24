#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
void out(int k) {
    cout<<n<<'=';
    for (int i=1;i<k;i++) cout<<a[i]<<'+';
    cout<<a[k];
    cout<<endl;
}
void rec(int k,int s,int mn) {
    for (int i=mn;i<=s;i++) {
        a[k]=i;
        if (s==i) out(k);
        else rec(k+1,s-i,i);
    }
}
int main() {
    cin>>n;
    rec(1,n,1);
}
