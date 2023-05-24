#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int n=s.length();
    int dem=0;
    for (int i=0;i<n/2;i++) {
        if (s[i]==s[n-i-1])
            dem+=1;
    }
    if (dem==n/2) {
        cout<<"1";
    } else {
        cout<<"0";
    }
}
