#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int dem=1;
    int n=s.length();
    for (int i=0;i<n;i++) {
        if (s[i]>='A'&&s[i]<='Z') {
            s[i]+=32;
        }
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if ((int)s[i]>(int)s[j]) {
                swap(s[i],s[j]);
            }
        }
    }
    while (s[0]==' ') {
        s.erase(0,1);
    }
    int m=s.length();
    for (int i=0;i<m-1;i++) {
        if (s[i]!=s[i+1])
            dem+=1;
    }
    cout<<dem;
}

