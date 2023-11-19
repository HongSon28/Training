#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int n=s.length(), m=n;
    for (int i=1;i<n;i++) {
        while (s[i]==' '&&s[i+1]==' ') {
            s.erase(i,1);
            m-=1;
        }
    }
    if (s[0]>='a'&&s[0]<='z')
        s[0]-=32;
    for (int i=1;i<m;i++) {
        if (s[i]>='a'&&s[i]<='z'&&s[i-1]==' ') {
            s[i]-=32;
        }
        if (s[i]>='A'&&s[i]<='Z'&&s[i-1]!=' ') {
            s[i]+=32;
        }
    }
    cout<<s;
}
