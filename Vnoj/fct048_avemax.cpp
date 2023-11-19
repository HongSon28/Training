#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    cout<<*max_element(a+1,a+1+n);
}
