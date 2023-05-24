#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int n=s.length();
    int dem=0;
    if (s[0]!=' ')
        dem=1;
    for (int i=1;i<n-1;i++) {
        if ((s[i]==' ')&&(s[i+1]!=' '))
            dem+=1;
    }
    cout<<dem;
}
