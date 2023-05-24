#include<bits/stdc++.h>
using namespace std;
int m,a,b;
bool check(int n) {
    int temp=n/a+n/b;
    if (temp>=m) return true;
    return false;
}
int main() {
    cin>>m;
    cin>>a>>b;
    m--;
    if (a>b) swap(a,b);
    int res=a;
    int lo=0,hi=1e9;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (check(mid)==true) hi=mid;
        else lo=mid+1;
    }
    cout<<res+lo;
}
