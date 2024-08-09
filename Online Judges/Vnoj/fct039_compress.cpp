#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n=s.size();
    for (int i=1;i<=n;i++) {
        if (n%i!=0) continue;
        int j=n/i;
        string t1=s.substr(0,i);
        string t2;
        for (int k=1;k<=j;k++) t2+=t1;
        if (t2==s) {
            cout<<j<<t1;
            return 0;
        }
    }
    cout<<1<<s;
}
