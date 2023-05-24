#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[11];
bool used[11];
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
    cin>>n>>k;
    rec(1,0);
}
