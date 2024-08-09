#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
int len;
int res;
int a[N+5];
bool check(int k) {
    int temp=sqrt(k*2);
    if (temp*(temp+1)/2==k) return true;
    return false;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (check(a[i])) {
            if (a[i]>=a[i-1]) len++;
            else len=1;
        } else len=0;
        res=max(res,len);
    }
    cout<<res;
}
