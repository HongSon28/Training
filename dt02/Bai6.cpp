#include<bits/stdc++.h>
int a[10],m;
bool check(int b) {
    int sl[10]={};
    while (b!=0) {
        sl[b%10]++;
        b/=10;
    }
    for (int i=0;i<=9;i++) {
        if (sl[i]>0) {
            int dem=0;
            for (int j=0;j<m;j++) {
                if (i==a[j]) {
                    dem++;
                }
            }
            if (dem==0)
                return false;
        }
    }
    return true;
}
using namespace std;
int main() {
    ifstream inp("boi.inp");
    ofstream out("boi.out");
    int n;
    inp>>n>>m;
    int c=0;
    for (int i=0;i<m;i++) {
        inp>>a[i];
        if (a[i]%2==0)
            c++;
    }
    int temp=n*2;
    if (c==0&&n%2!=0) {
        out<<"0";
        return 0;
    }
    while (check(temp)==false) {
        temp+=n;
    }
    out<<temp;
}
