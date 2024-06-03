#include<bits/stdc++.h>
using namespace std;
bool check(float n,int x) {
    if (n==(int)n) {
        if (n>0&&n!=x) {
            return true;
        }
    }
    return false;
}
int main() {
    int b,n;
    cin>>b>>n;
    int dem=0;
    for (int a=0;a<b;a++) {
        float m1=n-n*(sqrt(b*(b-a))/b);
        float m2=n+n*(sqrt(b*(b-a))/b);
        if (check(m1,n)==true) {
            dem++;
        }
        if (check(m2,n)==true) {
            dem++;
        }
    }
    cout<<dem;
}
