#include<bits/stdc++.h>
using namespace std;
int main () {
    string a,b;
    cin>>a>>b;
    unsigned dem=0;
    unsigned dai=a.length();
    for (unsigned i=0;i<dai;i++) {
        if (a[i]==b[i]) {
            dem+=1;
        }
    }
    if (dem==dai)
        cout<<"Yes";
    else
        cout<<"No";
}
