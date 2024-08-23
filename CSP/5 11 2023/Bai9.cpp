#include<bits/stdc++.h>
using namespace std;
int main() {
    string p,s;
    cin>>p>>s;
    int n=p.length(),m=s.length();
    for (int i=0;i<=m-n;i++) {
        string temp=s.substr(i,n);
        if (temp==p)
            cout<<i+1<<" ";
    }
}
