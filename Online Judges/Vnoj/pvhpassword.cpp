#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin>>s>>n;
    int a[123];
    for (int i=97;i<123;i++) {
        a[i]=n;
        n++;
        if (n>25)
            n-=26;
    }
    int dem=0;
    int m=s.length();
    for (int i=0;i<m;i++) {
        int temp=(int)s[i];
        dem+=a[temp];
    }
    cout<<dem;
}
